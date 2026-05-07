
# CPE310_Simon_Says_Final

## Structure (Auto Generated)

| Path                                       | Purpose                                                                                                                             |
|--------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------|
| _build                                     | The [CMake build tree](https://cmake.org/cmake/help/latest/manual/cmake.1.html#introduction-to-cmake-buildsystems), can be deleted. |
| cmake                                      | Generated [CMake](https://cmake.org/) files. May be deleted if user.cmake has not been added                                        |
| .vscode                                    | See [VSCode](https://code.visualstudio.com/docs/getstarted/settings)                                                                |
| .vscode\settings.json                      | Workspace specific settings                                                                                                         |
| .vscode\CPE310_Simon_Says_Final.mplab.json | The MPLAB project file, should not be deleted                                                                                       |
| out                                        | Final build artifacts                                                                                                               |

# Flashing and Hardware setup
Please have MPLab VSCode Extension Pack Installed

The MPLab Project automatically configures CMake and can be used for both building and flashing the program
This Project has only been verified to work on the ATMega328PB. I/O modifications may be required to support other devices.

| Pins | Function |
|------|----------|
| PORTD[0:7] | Button Matrix ROW[0:3]:COL[0:3] |
| PB2 | SPI Chip Select |
| PB3 | SPI MOSI (For LED Matrix) |
| PB5 | SPI Clock |
| PC4 | I2C DATA (For LCD) |
| PC5 | I2C Clock |
