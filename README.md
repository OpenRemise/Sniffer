# Sniffer

[![license](https://img.shields.io/github/license/OpenRemise/Sniffer)](https://github.com/OpenRemise/Sniffer/raw/master/LICENSE)

<a href="https://openremise.at">
<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://github.com/OpenRemise/.github/raw/master/data/icons/icon_dark.svg">
  <img src="https://github.com/OpenRemise/.github/raw/master/data/icons/icon_light.svg" width="20%" align="right">
</picture>
</a>

The sniffer is a small add-on board that turns a [Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico) into a [DCC](https://en.wikipedia.org/wiki/Digital_Command_Control) (and BiDi) sniffer for use with a logic analyzer.

### Features
- **Requires** [Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico) (or [Pico 2](https://www.raspberrypi.com/products/raspberry-pi-pico-2))
- No external supply
- Opto-isolation
- 3.3V logic level outputs for
  - P track
  - N track
  - BiDi
  - BiDi polarity
- Supported software
  - [PulseView](https://github.com/sigrokproject/pulseview)
  - [LogicAnalyzer](https://github.com/gusmanb/logicanalyzer)