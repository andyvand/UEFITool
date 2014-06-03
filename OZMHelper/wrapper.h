#ifndef WRAPPER_H
#define WRAPPER_H

#include "../basetypes.h"
#include "../ffsengine.h"

class Wrapper
{
public:
    Wrapper();
    ~Wrapper();
    /* Generic stuff */
    UINT8 fileOpen(QString path, QByteArray & buf);
    UINT8 fileWrite(QString path, QByteArray & buf);
    BOOLEAN fileExists(QString path);
    UINT8 dirCreate(QString path);
    BOOLEAN dirExists(QString path);
    QString pathConcatenate(QString path, QString filename);
    UINT32 getDateTime();
    /* Specific stuff */
    UINT8 dumpSectionByName(QString name, QByteArray & buf, UINT8 mode);
    UINT8 dumpSectionByGUID(QString guid, QByteArray & buf, UINT8 mode);
    UINT8 parseBIOSFile(QByteArray & buf);
    UINT8 getDSDTfromAMI(QByteArray in, QByteArray & out);
    UINT8 dsdt2bios(QByteArray amiboardinfo, QByteArray dsdt, QByteArray & out);
    UINT8 getInfoFromPlist(QByteArray plist, QString & name, QByteArray & out);
    UINT8 kext2ffs(QString basename, QString GUID, QByteArray inputbinary, QByteArray & output);

private:
    FfsEngine* ffsEngine;
};

#endif // WRAPPER_H
