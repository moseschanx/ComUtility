# packaging

Files that turn a build into what users download. CI (`.github/workflows/build.yml`) and
`scripts/package.ps1` use them.

| Folder | Contents |
|---|---|
| [windows/](windows/) | `ComUtility.iss`, the Inno Setup script for `ComUtility-<version>-windows-x64-setup.exe`, and `license.txt`, the licence page the installer shows. Build it with `.\scripts\package.ps1` (needs Inno Setup 6). |
| [macos/](macos/README.md) | `Info.plist.in`, the Info.plist of `ComUtility.app`; how the bundle and the disk images are made. |

The Linux tarball needs no files here: CI packs the `cmake --install` folder as it is.
