#ifndef POSDRIVER_H
#define POSDRIVER_H

#include <QObject>
#include "posdriverinterface.h"

class POSDriver : public QObject, public POSDriverInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "com.zomtronic.posdriver.01" FILE "")
#endif // QT_VERSION >= 0x050000
    Q_INTERFACES(POSDriverInterface)

public:
    explicit POSDriver(QObject *parent = 0);

    ESCPOSPrinter *getESCPOSPrinterInstance();
    GenericHIDScanner *getBarcodeScannerInstance();
    GenericHIDScanner *getMagneticScannerInstance();
    void processESCPOSPrinterASCIICommand(QString command);

private:
    ESCPOSPrinter *printer;
    GenericHIDScanner *barcodeScanner;
    GenericHIDScanner *magneticScanner;
};

#endif // POSDRIVER_H
