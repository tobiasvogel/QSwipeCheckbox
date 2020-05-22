#ifndef QSWIPECHECKBOXDESIGNERPLUGIN_H
#define QSWIPECHECKBOXDESIGNERPLUGIN_H

#include <QDesignerCustomWidgetInterface>
#include <QObject>
#include "qswipecheckbox.h"

class QSwipeCheckboxDesignerPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tv.tobiasvogel.code.qswipecheckbox")
    Q_INTERFACES(QDesignerCustomWidgetInterface)
public:
    explicit QSwipeCheckboxDesignerPlugin(QObject *parent = nullptr);

    bool isContainer() const override;
    bool isInitialized() const override;
    QIcon icon() const override;
    QString domXml() const override;
    QString group() const override;
    QString includeFile() const override;
    QString name() const override;
    QString toolTip() const override;
    QString whatsThis() const override;
    QWidget *createWidget(QWidget *parent) override;
    void initialize(QDesignerFormEditorInterface *core) override;

private:
    bool initialized = false;
};

#endif // QSWIPECHECKBOXDESIGNERPLUGIN_H
