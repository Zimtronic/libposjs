#include "posdriver.h"

#include "escposprinter.h"
#include "generichidscanner.h"

#include <QStringList>

POSDriver::POSDriver(QObject *parent) :
    QObject(parent)
{
    printer = new ESCPOSPrinter();
    printer->setName("ESCPOSPrinter");
    printer->setIdProduct(0x0e15);
    printer->setIdVendor(0x04b8);

    barcodeScanner = new GenericHIDScanner();
    barcodeScanner->setName("BarcodeScanner");
    barcodeScanner->setIdProduct(0x1010);
    barcodeScanner->setIdVendor(0x05FE);
    barcodeScanner->start();

    magneticScanner = new GenericHIDScanner();
    magneticScanner->setName("MagneticScanner");
    magneticScanner->setIdProduct(0x0001);
    magneticScanner->setIdVendor(0x0801);
    magneticScanner->start();
}

ESCPOSPrinter *POSDriver::getESCPOSPrinterInstance()
{
    return printer;
}

GenericHIDScanner *POSDriver::getBarcodeScannerInstance()
{
    return barcodeScanner;
}

GenericHIDScanner *POSDriver::getMagneticScannerInstance()
{
    return magneticScanner;
}

void POSDriver::processESCPOSPrinterASCIICommand(QString command)
{
    QString d, path;
    QStringList l;

    switch ((int)command[0].toLatin1())
    {
        case 'i':
            printer->init();
            break;
        case '0':
            printer->printRawText(command.right(command.length()-1));
            break;
        case '1':
            printer->cutPaper();
            break;
        case '2':
            printer->sendPulseToCashDrawer(int(command[1].toLatin1() - 48));
            break;
        case '3':
            d = command.right(command.length()-1);
            l = d.split(':');
            if (l.length() == 5)
            {
                printer->setTextProperties(l.at(0).toInt(), l.at(1).toInt(),
                                           l.at(2).toInt(), l.at(3).toInt(),
                                           l.at(4).toInt());
            }
            break;
        case '4':
            d = command.right(command.length()-1);
            printer->feedControl(d.toInt());
            break;
        case '5':
            d = command.right(command.length()-1);
            l = d.split(':');
            if(l.length() > 1)
            {
                d = d.right(d.length() - l.at(0).length() - 1);
                path = d.left(l.at(0).toInt());
                d = d.right(d.length() - path.length());
                l = d.split(':');
                if(l.length() > 1)
                {
                    printer->printImage(path, l.at(0).toInt(), l.at(1).toInt());
                }
            }
            break;
        case '6':
            printer->init();
            break;
        case '7':
            printer->init();
            break;
        case '8':
            printer->init();
            break;
        default:
            qDebug() << "default: " << (int)command[0].toLatin1();
            break;
    }

}
