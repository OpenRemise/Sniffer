// Copyright (C) 2026 Vincent Hamp
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

/// Documentation
///
/// \file   doxygen.hpp
/// \author Vincent Hamp
/// \date   18/06/2026

/// \details
/// Welcome to the OpenRemise [Sniffer](https://github.com/OpenRemise/Sniffer)
/// documentation, a tiny [Raspberry Pi
/// Pico](https://www.raspberrypi.com/products/raspberry-pi-pico) based
/// [DCC](https://en.wikipedia.org/wiki/Digital_Command_Control) (and BiDi)
/// logic analyzer.
///
/// \note
/// This documentation is intended for developers. General information on usage
/// can be found on the main page at [openremise.at](https://openremise.at).
///
// clang-format off
/// \mainpage Introduction
/// | Getting Started                                                                                                                                                                                                                                | HW Reference                                                                                                                 |
/// | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
/// | [![](stopwatch.svg)](page_getting_started.html)                                                                                                                                                                                                | [![](pcb.svg)](page_hw_reference.html)                                                                                       |
/// | <div style="max-width:200px">New to logic analyzers? Check out the \ref page_getting_started guide. Flash [sigrok-pico](https://github.com/pico-coder/sigrok-pico) and install [PulseView](https://github.com/sigrokproject/pulseview). </div> | <div style="max-width:200px">Browse schematics and layouts of the Sniffer board in the \ref page_hw_reference section.</div> |
///
/// <div class="section_buttons">
/// | Next                      |
/// | ------------------------: |
/// | \ref page_getting_started |
/// </div>
// clang-format on

/// \page page_getting_started Getting Started
/// \details \tableofcontents
/// In this guide, we will look at how to get the Sniffer up and running. This
/// includes flashing the
/// [sigrok-pico](https://github.com/pico-coder/sigrok-pico) firmware onto a
/// [Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico)
/// (or [Pico2](https://www.raspberrypi.com/products/raspberry-pi-pico-2)),
/// installing [PulseView](https://github.com/sigrokproject/pulseview) including
/// the necessary [DCC](https://en.wikipedia.org/wiki/Digital_Command_Control)
/// decoder, and finally capturing a DCC trace.
///
/// \section section_getting_started_prerequisites Prerequisites
/// Before we can get started, however, we need one thing above all: the Sniffer
/// board. Due to the presumably small number of units, I unfortunately cannot
/// provide the Sniffer pre-assembled. Instead, the **PCB must be manufactured**
/// by a PCB prototyping service such as [PCBWay](https://www.pcbway.com).
/// However, the board is only two layers and should therefore be very
/// inexpensive.
///
/// Besides the PCB itself, we also need the components. Care was taken to use
/// large footprints to allow for manual soldering. The required components can
/// be found either in the [BOM
/// (.xlsx)](https://github.com/OpenRemise/Sniffer/raw/master/bom.xlsx) or this
/// shared [DigiKey list](https://www.digikey.at/en/mylists/list/8791OT30HK).
///
/// At the time of writing, the component costs amount to approximately **€16**.
///
/// \section section_getting_started_sigrok_pico Flash sigrok-pico
/// Once the PCB is soldered, the appropriate firmware from the
/// [sigrok-pico](https://github.com/pico-coder/sigrok-pico) project must be
/// flashed onto the Pico (or Pico2). **Depending on the model**, you will need
/// one of the following firmware versions.
/// <div class="tabbed">
/// - <b class="tab-title">Pico</b>
///   [pico_dig26.uf2](https://github.com/pico-coder/sigrok-pico/raw/main/pico_sdk_sigrok/release/pico_dig26.uf2)
/// - <b class="tab-title">Pico2</b>
///   [pico2_dig26.uf2](https://github.com/pico-coder/sigrok-pico/raw/main/pico_sdk_sigrok/release/pico2_dig26.uf2)
/// </div>
///
/// Fortunately, a connected Pico registers as a mass storage device on the PC,
/// and the firmware can therefore be easily dragged and dropped onto the
/// appearing drive. No need for installers whatsoever.
///
/// \section section_getting_started_pulse_view Install PulseView
/// Next, we will install
/// [PulseView](https://github.com/sigrokproject/pulseview), an GPL3 licensed
/// logic analyzer software from the company Sigrok. Unfortunately, PulseView
/// releases very infrequently, which is why we **must** install the continuous
/// **nightly build**. The last stable version 0.4.2 is so old that it doesn't
/// yet include the necessary drivers...
///
/// Here are the links to the AppImage or installer.
/// <div class="tabbed">
/// - <b class="tab-title">Linux</b>
///   [pulseview-NIGHTLY-x86_64-release.appimage](https://github.com/sigrokproject/pulseview/releases/download/continuous/pulseview-NIGHTLY-x86_64-release.appimage)
/// - <b class="tab-title">Windows</b>
///   [pulseview-NIGHTLY-x86_64-release-installer.exe](https://github.com/sigrokproject/pulseview/releases/download/continuous/pulseview-NIGHTLY-x86_64-release-installer.exe)
/// </div>
///
/// \subsection subsection_getting_started_decoder Add DCC Decoder
/// Last but not least, we also need the DCC decoder, which the company
/// [ZIMO](https://www.zimo.at) kindly provides as an open source. An attempt
/// has also been made to upstream this decoder, but whether it will ever end up
/// in the official repository remains to be seen.
///
/// Here is the link to the fork containing the DCC decoder.<br>
/// https://github.com/ZIMO-Elektronik/libsigrokdecode/tree/dcc
///
/// The folder `/decoders/dcc` of this repository must be copied to the
/// following user folder so that it is visible to PulseView.
///
/// <div class="tabbed">
/// - <b class="tab-title">Linux</b>
///   ```sh
///   ~/.local/share/libsigrokdecode/decoders
///   ```
/// - <b class="tab-title">Windows</b>
///   ```sh
///   C:\Users\YourUsername\AppData\Local\libsigrokdecode\decoders
///   ```
/// </div>
///
/// For simplicity, the following script can also be copied and executed. It
/// creates the folder and downloads the necessary files.
// clang-format off
/// \page page_getting_started Getting Started
/// \details \tableofcontents
/// <div class="tabbed">
/// - <b class="tab-title">Linux</b>
///   ```sh
///   mkdir -p ~/.local/share/libsigrokdecode/decoders/dcc
///   cd ~/.local/share/libsigrokdecode/decoders/dcc
///   curl -L -o __init__.py https://github.com/ZIMO-Elektronik/libsigrokdecode/raw/dcc/decoders/dcc/__init__.py
///   curl -L -o lists.py    https://github.com/ZIMO-Elektronik/libsigrokdecode/raw/dcc/decoders/dcc/lists.py
///   curl -L -o pd.py       https://github.com/ZIMO-Elektronik/libsigrokdecode/raw/dcc/decoders/dcc/pd.py
///   ```
/// - <b class="tab-title">Windows</b>
///   ```sh
///   mkdir "%USERPROFILE%\.local\share\libsigrokdecode\decoders\dcc"
///   cd /d "%USERPROFILE%\.local\share\libsigrokdecode\decoders\dcc"
///   curl -L -o __init__.py https://github.com/ZIMO-Elektronik/libsigrokdecode/raw/dcc/decoders/dcc/__init__.py
///   curl -L -o lists.py    https://github.com/ZIMO-Elektronik/libsigrokdecode/raw/dcc/decoders/dcc/lists.py
///   curl -L -o pd.py       https://github.com/ZIMO-Elektronik/libsigrokdecode/raw/dcc/decoders/dcc/pd.py
///   ```
/// </div>
// clang-format on
/// \page page_getting_started Getting Started
/// \details \tableofcontents
///
/// \section section_getting_started_capture Capture a Trace
/// Once we have a working board and installation, we can start capturing a
/// trace. So we plug in the board (I assume the cabling is self-explanatory)
/// and start PulseView.
///
/// \subsection subsection_getting_started_capture_connect Connect to Device
/// Click the device selection drop down and chose the
/// `RaspberryPI PICO (raspberrypi-pico)` driver. Select `Serial Port` as
/// interface and pick the port. The naming should help in selecting the right
/// one (`/dev/ttyACM0 (Pico - F020035836D7A1C3)` in my case). Afterwards click
/// `Scan for devices using driver above` and your Sniffer board should appear
/// in the frame below. Select it and click `OK` to close the window.
///
/// \subsection subsection_getting_started_capture_configure Configure Channels
/// Click the &nbsp; \image{inline} html channels.svg width=16px red probe icon
/// to open the configuration window for the channels. Enable the channels from
/// the following table. Optionally, you can also rename the channels to their
/// DCC names; they will then be automatically assigned when selecting the
/// decoder.
///
/// | PulseView | DCC  |
/// | --------- | ---- |
/// | D2        | NC   |
/// | D3        | NC   |
/// | D4        | P    |
/// | D5        | N    |
/// | D6        | BIDI |
///
/// \warning
/// Please note that channels D2 and D3 **must** remain enabled even when not in
/// use. This is a limitation of the sigrok-pico firmware, which was
/// intentionally accepted to support the
/// [LogicAnalyzer](https://github.com/gusmanb/logicanalyzer) firmware as an
/// alternative. LogicAnalyzer uses these two pins (GPIO0 and GPIO1 on the Pico)
/// as optional triggers.
///
/// Select the number of samples to be recorded and then increase the sample
/// rate to **at least 1MHz**. Anything below that will result in an error
/// message.
///
/// \note
/// When you hover your mouse cursor over one of the settings, the total
/// sampling time will be displayed.
///
/// Now click &nbsp; \image{inline} html status-grey.svg width=16px Run and you
/// should see samples getting captured.
///
/// \subsection subsection_getting_started_capture_decoder Add Protocol Decoder
/// Now the DCC decoder needs to be loaded. To do this, click the &nbsp;
/// \image{inline} html add-decoder.svg width=16px yellow/green pulse icon and
/// search for DCC. Unless the channel names have been changed, the channels
/// must now be manually assigned to their signals.
///
/// \note
/// If you running on a toaster, processing the samples can take quite a long
/// time. After all, the decoder is Python\htmlonly&#128013;\endhtmlonly.
///
/// \subsection subsection_getting_started_capture_tl_dr tl;dr
// clang-format off
/// \page page_getting_started Getting Started
/// \details \tableofcontents
/// \htmlonly
/// <div class="image">
/// <iframe width="640" height="260" src="capture_a_trace.webm" title="Capturing a trace" allow="picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
/// <div class="caption">Capturing a trace</div>
/// </div>
/// \endhtmlonly
// clang-format on
/// \page page_getting_started Getting Started
/// \details \tableofcontents
///
/// <div class="section_buttons">
/// | Previous   | Next                   |
/// | :--------- | ---------------------: |
/// | \ref index | \ref page_hw_reference |
/// </div>

/// \page page_hw_reference HW Reference
/// \details
/// \htmlonly
/// <script type="module" src="kicanvas.js"></script>
/// \endhtmlonly
///
/// \htmlonly
/// <kicanvas-embed controls="full">
///   <kicanvas-source src="sniffer.kicad_sch"></kicanvas-source>
///   <kicanvas-source src="sniffer.kicad_pcb"></kicanvas-source>
/// </kicanvas-embed>
/// \endhtmlonly
///
/// <div class="section_buttons">
/// | Previous          |
/// | :---------------- |
/// | \ref page_getting_started |
/// </div>
