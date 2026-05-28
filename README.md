# Equinios

A lightweight logging library for embedded systems (Nios II / bare-metal), written in C.

The project provides a ring-buffer-based queue, log-level filtering, timestamps, and periodic buffer flushing via `log_process()`.

## Key Features

- log levels: `CRITICAL`, `ERROR`, `WARNING`, `INFO`, `DEBUG`, `TRACE`,
- convenience logging macros: `LOGC`, `LOGE`, `LOGW`, `LOGI`, `LOGD`, `LOGT`,
- configurable timestamp provider (`log_set_timestamp_provider`),
- dropped-line counter for ring buffer overflow,
- static library build output: `libEquiniosLogger.a`.

## Repository Structure

- `include/` - public API headers,
- `src/` - implementation,
- `api/` - umbrella application header (`equinios.hpp`),
- `examples/NiosLoggerDemo/` - minimal Nios II usage example,
- `Makefile` - library build script.

## Public API

Main C header:

- `include/equinios.h`

Exposed functions:

- `log_set_level(...)`
- `log_set_process_every_n_calls(...)`
- `log_set_timestamp_provider(...)`
- `log_get_dropped_lines()`
- `log_reset_dropped_lines()`
- `log_write(...)`
- `log_process()`

## Quick Start (Library)

Required tools:

- `make`,
- Nios II toolchain in PATH (default prefix: `nios2-elf-`).

Build the library:

```bash
make
```

Clean build artifacts:

```bash
make clean
```

Build output:

- `libEquiniosLogger.a`

## Application Example

The demo is located in:

- `examples/NiosLoggerDemo/`

Run instructions and hardware requirements are described in:

- `examples/NiosLoggerDemo/README.md`

## License

BSD 3-Clause - see `LICENSE` for details.
