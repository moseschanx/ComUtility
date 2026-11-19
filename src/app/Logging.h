#pragma once

#include <QLoggingCategory>

// Logging categories used throughout the application.
//
// Usage:   qCInfo(lcSerial) << "opened" << portName;
//          qCWarning(lcTerminal) << "unknown CSI" << final;
//
// All Qt messages (qDebug/qInfo/qWarning/qCritical, categorised or not) are routed by
// SystemLogViewer::installMessageHandler() into the in-app "System Log" dock as well as
// to the default handler (stderr / debugger output). Category names are prefixed with
// "comutility." so they can be filtered with QT_LOGGING_RULES, e.g.
//     QT_LOGGING_RULES="comutility.terminal.debug=true"

Q_DECLARE_LOGGING_CATEGORY(lcApp)       // "comutility.app"      application lifecycle, settings
Q_DECLARE_LOGGING_CATEGORY(lcSerial)    // "comutility.serial"   port enumeration, open/close, errors
Q_DECLARE_LOGGING_CATEGORY(lcTerminal)  // "comutility.terminal" parser / screen model
Q_DECLARE_LOGGING_CATEGORY(lcUi)        // "comutility.ui"       widgets, dialogs
Q_DECLARE_LOGGING_CATEGORY(lcSsh)       // "comutility.ssh"      SSH sessions (libssh), profiles, secrets
Q_DECLARE_LOGGING_CATEGORY(lcFirmware)  // "comutility.firmware" Firmware tab: tools, flashing, CC1310 updater, image pull (v0.5)
