# timeused

A completely minimal, zero-filler command-line tool for Windows that returns your exact system uptime in a clean `H:MM:SS` digital clock format.

## Features
* **Zero Filler:** No loading text, headers, or generic system chat.
* **Lightweight:** Raw compiled C binary with zero dependencies.
* **Instant:** Grabs the native Windows kernel tick count directly.

## Usage
Open **Command Prompt (cmd)** and run:
```cmd
timeused
```

### Output Example
`4:12:05`

---

## Installation & Setup
For full step-by-step setup instructions to deploy the pre-compiled executable globally, see the [Installation Guide](INSTALL.md).

## Build from Source (Optional)
If you want to compile the code yourself instead of using a release binary, you can use the provided build script or compile directly using `kcc`:

```cmd
kcc timeused.c -o build\timeused.exe
```
*(Note: If you are using the automated batch script, it will handle compilation and automatically move the final binary into the `build` directory).*
