# Green Software Efficiency Analysis

## Measurement Methodology

To evaluate software execution efficiency under controlled conditions, all benchmarks were compiled and executed within the same Linux environment using strict ANSI C (`-std=gnu89`) compiler flags (`-Wall -Werror -Wextra -pedantic -Wno-long-long`). Execution time was measured programmatically using the standard `<time.h>` library by capturing CPU clock ticks via `clock()` immediately before and after target code blocks, then converting the elapsed ticks into seconds using `CLOCKS_PER_SEC`.

Three experiments were conducted:
1. **Baseline Execution (`baseline_loop.c`):** Executed a deterministic loop of `100,000,000` iterations three consecutive times to observe baseline timing behavior and system-induced variance.
2. **Algorithmic Comparison (`comparison_algorithms.c`):** Measured two functions counting even integers across a static array of `50,000` elements over three consecutive runs to compare quadratic $O(N^2)$ and linear $O(N)$ implementations.
3. **Controlled Instrumentation (`instrumentation_lab.c`):** Placed phase-level timing boundaries around data generation (`build_dataset`), transformation (`process_dataset`), and aggregation (`reduce_checksum`) alongside an overarching total timer (`TOTAL`).

## Observed Performance Differences

In the baseline experiment (`100,000,000` iterations), the three runs recorded `0.197645`, `0.197296`, and `0.197338` seconds, demonstrating minor run-to-run variance around `0.1974` seconds due to background OS scheduling.

In the algorithmic comparison over `50,000` elements, the naive nested-loop algorithm averaged `0.669637` seconds across three runs (`0.673561`, `0.668148`, and `0.667203` seconds). Conversely, the single-pass algorithm averaged `0.000028` seconds (`0.000028`, `0.000029`, and `0.000028` seconds). The naive implementation was approximately **23,634 times slower** than the single-pass approach while producing the same logical count per pass.

In the multi-phase instrumentation experiment, total execution took `0.000360` seconds, distributed across `BUILD_DATA` (`0.000152` seconds), `PROCESS` (`0.000141` seconds), and `REDUCE` (`0.000065` seconds). The sum of individual phases (`0.000358` seconds) closely aligns with `TOTAL`, confirming minimal instrumentation overhead while showing that data generation and arithmetic processing accounted for over 81% of execution time.

## Relation Between Runtime and Energy Consumption

While these experiments did not measure physical electrical draw in watts, CPU execution time serves as a direct proxy for computational energy consumption. An active processor core executing instructions consumes significantly more dynamic power than an idle core in a low-power sleep state. Because the naive $O(N^2)$ algorithm kept the CPU actively computing for `0.669637` seconds compared to `0.000028` seconds for the $O(N)$ version, it forced the processor to remain in an active high-power state over twenty thousand times longer. When scaled across millions of daily invocations in production data centers, inefficient algorithms directly translate into higher electricity usage, increased thermal dissipation, and greater carbon emissions.

## Limitations of the Experiment

Several constraints limit the scope of these measurements:
- **No Direct Hardware Power Telemetry:** Using `clock()` measures CPU time rather than actual energy in joules or power in watts (such as Intel RAPL counters), ignoring hardware-specific voltage scaling and memory bus power draw.
- **Timer Granularity on Micro-Benchmarks:** Sub-millisecond phases like `REDUCE` (`0.000065` seconds) approach the resolution limits of `clock()`, making ultra-short intervals sensitive to OS context switches and timer rounding.
- **Controlled Single-Threaded Scope:** All benchmarks ran single-threaded on small static datasets without I/O, network latency, or compiler optimization flags (`-O2`/`-O3`), which would alter real-world execution profiles.

## Practical Engineering Takeaway

Evidence-based profiling must precede optimization. As demonstrated in `instrumentation_lab.c`, breaking a workload into distinct phases identifies where CPU cycles are actually spent (`BUILD_DATA` and `PROCESS` rather than `REDUCE`). Furthermore, optimizing algorithmic complexity yields orders-of-magnitude gains—such as reducing runtime from `0.669637` seconds to `0.000028` seconds—far outweighing micro-optimizations. By systematically measuring execution time as a sustainability proxy and eliminating redundant computational complexity, engineers can deliver faster software with a substantially smaller energy footprint.
