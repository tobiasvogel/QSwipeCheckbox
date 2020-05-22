#ifndef QSWIPECHECKBOX_H
#define QSWIPECHECKBOX_H

#include <QObject>
#include <QWidget>
#include <QAbstractButton>
#include <QMetaEnum>

QT_BEGIN_NAMESPACE

class QSwipeCheckbox : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor activeBackgroundColor READ getActiveBackgroundColor WRITE setActiveBackgroundColor DESIGNABLE true)
    Q_PROPERTY(QColor inactiveBackgroundColor READ getInactiveBackgroundColor WRITE setInactiveBackgroundColor DESIGNABLE true)
    Q_PROPERTY(QColor activeTextColor READ getActiveTextColor WRITE setActiveTextColor DESIGNABLE true)
    Q_PROPERTY(QColor inactiveTextColor READ getInactiveTextColor WRITE setInactiveTextColor DESIGNABLE true)
    Q_PROPERTY(QColor activeBorderColor READ getActiveBorderColor WRITE setActiveBorderColor DESIGNABLE true)
    Q_PROPERTY(QColor inactiveBorderColor READ getInactiveBorderColor WRITE setInactiveBorderColor DESIGNABLE true)
    Q_PROPERTY(QColor activeSwitchBorderColor READ getActiveSwitchBorderColor WRITE setActiveSwitchBorderColor DESIGNABLE true)
    Q_PROPERTY(QColor inactiveSwitchBorderColor READ getInactiveSwitchBorderColor WRITE setInactiveSwitchBorderColor DESIGNABLE true)
    Q_PROPERTY(QColor activeSwitchKnobColor READ getActiveSwitchKnobColor WRITE setActiveSwitchKnobColor DESIGNABLE true)
    Q_PROPERTY(QColor inactiveSwitchKnobColor READ getInactiveSwitchKnobColor WRITE setInactiveSwitchKnobColor DESIGNABLE true)
    Q_PROPERTY(QColor activePaddingColor READ getActivePaddingColor WRITE setActivePaddingColor DESIGNABLE true)
    Q_PROPERTY(QColor inactivePaddingColor READ getInactivePaddingColor WRITE setInactivePaddingColor DESIGNABLE true)
    Q_PROPERTY(QString activeText READ activeText WRITE setActiveText DESIGNABLE true)
    Q_PROPERTY(QString inactiveText READ inactiveText WRITE setInactiveText DESIGNABLE true)
    Q_PROPERTY(int borderWidth READ borderWidth WRITE setBorderWidth DESIGNABLE true)
    Q_PROPERTY(int paddingWidth READ paddingWidth WRITE setPaddingWidth DESIGNABLE true)
    Q_PROPERTY(int switchKnobSize READ switchKnobSize WRITE setSwitchKnobSize DESIGNABLE true)
    Q_PROPERTY(QSize size READ getSize WRITE setSize NOTIFY sizeChanged DESIGNABLE false USER false)
    Q_PROPERTY(int animationSpeed READ animationSpeed WRITE setAnimationSpeed DESIGNABLE true)
    Q_PROPERTY(QFont activeTextFont READ activeTextFont WRITE setActiveTextFont DESIGNABLE true)
    Q_PROPERTY(QFont inactiveTextFont READ inactiveTextFont WRITE setInactiveTextFont DESIGNABLE true)
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked NOTIFY stateChanged DESIGNABLE true)
    Q_PROPERTY(float animationState READ animationState WRITE setAnimationState DESIGNABLE false USER false)
    Q_PROPERTY(QColor renderBackgroundColor READ renderBackgroundColor WRITE setRenderBackgroundColor  DESIGNABLE false USER false)
    Q_PROPERTY(QColor renderBorderColor READ renderBorderColor WRITE setRenderBorderColor DESIGNABLE false USER false)
    Q_PROPERTY(QColor renderKnobBorderColor READ renderKnobBorderColor WRITE setRenderKnobBorderColor DESIGNABLE false USER false)
    Q_PROPERTY(QColor renderKnobColor READ renderKnobColor WRITE setRenderKnobColor  DESIGNABLE false USER false)
    Q_PROPERTY(QColor renderPaddingColor READ renderPaddingColor WRITE setRenderPaddingColor DESIGNABLE false USER false)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled DESIGNABLE true)
    Q_PROPERTY(DisplayStyle displayStyle READ getDisplayStyle WRITE setDisplayStyle DESIGNABLE true USER true)
    Q_PROPERTY(ClickableArea clickableArea READ getClickableArea WRITE setClickableArea DESIGNABLE true USER true)

public:
    enum DisplayStyle { Classic, iOS, Material, Windows };
    enum ClickableArea { Full, Text, Knob, KnobAndText };
    Q_ENUM(DisplayStyle)
    Q_ENUM(ClickableArea)

    explicit QSwipeCheckbox(QWidget *parent = nullptr);
    ~QSwipeCheckbox();

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    bool isChecked(void) const;
    bool checked(void) const;
    void setChecked(bool checked);

    bool checkState() const;
    void setCheckState(bool state);
    void setCheckState(Qt::CheckState state);
    void setCheckState(int state);

    void setEnabled(bool enabled);
    bool isEnabled(void) const;
    bool enabled(void) const;

    void setActiveText(QString text);
    void setInactiveText(QString text);

    QString activeText(void) const;
    QString inactiveText(void) const;

    int borderWidth(void) const;
    void setBorderWidth(int width = 1);

    int paddingWidth(void) const;
    void setPaddingWidth(int width = 1);

    int switchKnobSize(void) const;
    void setSwitchKnobSize(int diameter = 18);

    void setActiveBackgroundColor(QColor color);
    void setInactiveBackgroundColor(QColor color);
    void setActiveTextColor(QColor color);
    void setInactiveTextColor(QColor color);
    void setActiveBorderColor(QColor color);
    void setInactiveBorderColor(QColor color);
    void setActiveSwitchBorderColor(QColor color);
    void setInactiveSwitchBorderColor(QColor color);
    void setActiveSwitchKnobColor(QColor color);
    void setInactiveSwitchKnobColor(QColor color);
    void setActivePaddingColor(QColor color);
    void setInactivePaddingColor(QColor color);

    QColor getActiveBackgroundColor(void) const;
    QColor getActiveTextColor(void) const;
    QColor getInactiveBackgroundColor(void) const;
    QColor getInactiveTextColor(void) const;
    QColor getActiveBorderColor(void) const;
    QColor getInactiveBorderColor(void) const;
    QColor getActiveSwitchBorderColor(void) const;
    QColor getInactiveSwitchBorderColor(void) const;
    QColor getActiveSwitchKnobColor(void) const;
    QColor getInactiveSwitchKnobColor(void) const;
    QColor getActivePaddingColor(void) const;
    QColor getInactivePaddingColor(void) const;

    void setAnimationSpeed(int milliseconds = 330);

    QFont activeTextFont(void) const;
    QFont inactiveTextFont(void) const;

    void setActiveTextFont(const QFont &font);
    void setInactiveTextFont(const QFont &font);

    void setWidth(int width);
    void setHeight(int height);
    void setSize(int width, int height);
    void setSize(const QSize &size);

    QSize getSize(void) const;

    int animationSpeed(void) const;

    DisplayStyle getDisplayStyle(void) const;
    QString getDisplayStyleName(void) const;

    void setDisplayStyle(DisplayStyle style);
    void setDisplayStyle(QString style);

    ClickableArea getClickableArea(void) const;
    QString getClickableAreaName(void) const;

    void setClickableArea(ClickableArea area);
    void setClickableArea(QString area);

Q_SIGNALS:
    void sizeChanged(QSize);
    void stateChanged(bool state);


protected:
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

protected Q_SLOTS:
    void animationStopped(void);

private:
    void paintClassicStyleSwitchElements(QPainter &p, QPainterPath &clippingPath);
    void paintiOSStyleSwitchElements(QPainter &p, QPainterPath &clippingPath);
    void paintMaterialStyleSwitchElements(QPainter &p, QPainterPath &clippingPath);
    void paintWindowsStyleSwitchElements(QPainter &p, QPainterPath &clippingPath);

    void setRenderBackgroundColor(QColor color);
    void setRenderKnobColor(QColor color);
    void setRenderKnobBorderColor(QColor color);
    void setRenderBorderColor(QColor color);
    void setRenderPaddingColor(QColor color);

    QColor renderBackgroundColor(void) const;
    QColor renderKnobColor(void) const;
    QColor renderBorderColor(void) const;
    QColor renderKnobBorderColor(void) const;
    QColor renderPaddingColor(void) const;

    void runAnimation();

    float animationState(void) const;
    void setAnimationState(float state);

    void initialize(void);
    bool isInitialized(void) const;

    void resetColors(void);

private:
    QString m_activeText;
    QString m_inactiveText;
    QColor m_activeBackgroundColor;
    QColor m_activeTextColor;
    QColor m_inactiveBackgroundColor;
    QColor m_inactiveTextColor;
    QColor m_activeBorderColor;
    QColor m_inactiveBorderColor;
    QColor m_activeSwitchBorderColor;
    QColor m_inactiveSwitchBorderColor;
    QColor m_activeSwitchKnobColor;
    QColor m_inactiveSwitchKnobColor;
    QColor m_activePaddingColor;
    QColor m_inactivePaddingColor;
    QColor m_renderBackgroundColor;
    QColor m_renderBorderColor;
    QColor m_renderKnobBorderColor;
    QColor m_renderKnobColor;
    QColor m_renderPaddingColor;
    int m_animationSpeed;
    int m_borderWidth;
    int m_paddingWidth;
    int m_switchKnobSize;
    QSize m_size;
    QFont m_activeTextFont;
    QFont m_inactiveTextFont;
    bool m_checkState;
    QRect m_mouseHoverRect;
    QRect m_knobRect;
    QPainterPath m_mouseHoverRegion;
    bool m_animationIsRunning = false;
    int m_leftPosition;
    int m_rightPosition;
    QSize m_widgetSize;
    int m_widgetDiameter;
    int m_widgetRadius;
    QRectF m_activeTextRect;
    QRectF m_inactiveTextRect;
    float m_animationState;
    bool m_enabled;
    bool m_initialized = false;
    DisplayStyle m_displayStyle = DisplayStyle::Classic;
    ClickableArea m_clickableArea = ClickableArea::Knob;

};

QT_END_NAMESPACE

#endif // QSWIPECHECKBOX_H
