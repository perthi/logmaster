// GUICringAbsolutePos.h
// karl eirik bang fossberg

#ifndef GUI_CRING_ABSOLUTE_POS_H
#define GUI_CRING_ABSOLUTE_POS_H

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
//#include <api/api-hmi/APICRingEnums.h>
#include <memory>

class GUICringAbsolutePos : public QWidget
{
    Q_OBJECT

public:
    GUICringAbsolutePos(QWidget *pParent = nullptr);
    ~GUICringAbsolutePos();

signals:
    void signalUpdateTextfieldTranslation(double translation);
    void signalUpdateTextfieldRotation(double rotation);
    void signalApplyAbsolutePositionInternal(double translation,
        double rotation);

public slots:
    void slotSetTranslationAbsolute(double relValue);
    void slotSetRotationAbsolute(double relValue);
    void slotUpdateTextfieldTranslation(double translation);
    void slotUpdateTextfieldRotation(double rotation);
    void slotApplyAbsolutePosition();

    virtual void slotUpdateRevolutionsInternal(int revolutions){};

protected:
    std::unique_ptr<QGridLayout> m_pLayout;

private:
    double m_translation;
    double m_rotation;
};

#endif // GUI_CRING_ABSOLUTE_POS_H
