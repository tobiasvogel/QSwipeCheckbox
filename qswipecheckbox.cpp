#include "qswipecheckbox.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QtMath>

QSwipeCheckbox::QSwipeCheckbox(QWidget *parent) : QWidget(parent) {
    /*!
        \class QSwipeCheckbox
        \brief Flippable-Style Checkbox for the Qt Framework.

        \ingroup basicwidgets
        \inmodule QtWidgets
    */
    /*!
        \property QSwipeCheckbox::activeBackgroundColor()
        \brief This property holds the Background Color for the active state.

        \sa inactiveBackgroundColor
    */

    /*!
        \property QSwipeCheckbox::inactiveBackgroundColor()
        \brief This property holds the Background Color for the inactive state.

        \sa activeBackgroundColor
    */

    /*!
        \property QSwipeCheckbox::activeTextColor()
        \brief This property holds the Text Color for the active state.

        \sa inactiveTextColor
    */

    /*!
        \property QSwipeCheckbox::inactiveTextColor()
        \brief This property holds the Text Color for the inactive state.

        \sa activeTextColor
    */

    /*!
        \property QSwipeCheckbox::activeBorderColor()
        \brief This property holds the Border Color for the active state.
    */

    /*!
        \property QSwipeCheckbox::inactiveBorderColor()
        \brief This property holds the Border Color for the inctive state.
    */

    /*!
        \property QSwipeCheckbox::activeSwitchKnobColor
        \brief This property holds the inner Knob/Handle Color for the active state.

        \sa inactiveSwitchKnobColor
    */

    /*!
        \property QSwipeCheckbox::inactiveSwitchKnobColor
        \brief This property holds the inner knob/handle color for the inactive state.

        \sa activeSwitchKnobColor
    */

    /*!
        \property QSwipeCheckbox::activeText
        \brief This property holds the text for the active state.

        \sa inactiveText
    */

    /*!
        \property QSwipeCheckbox::inactiveText
        \brief This property holds the text for the inactive state.

        \sa activeText
    */

    /*!
        \property QSwipeCheckbox::borderWidth
        \brief This property holds the width of the QSwipeCheckbox border.

        This property's default is 2.
    */

    /*!
        \property QSwipeCheckbox::switchKnobSize
        \brief This property holds the size (diameter) of the QSwipeCheckbox knob/handle.
    */
    /*!
        \property QSwipeCheckbox::animationSpeed
        \brief This property holds the speed (duration) of the animation.

        Setting this value to 0 disables the animation (instant switch flip).
    */

    /*!
        \property QSwipeCheckbox::activeTextFont
        \brief This property holds the font style for the active state.

        \sa inactiveTextFont
    */

    /*!
        \property QSwipeCheckbox::inactiveTextFont
        \brief This property holds the font style for the inactive state.

        \sa activeTextFont
    */

    /*!
        \property QSwipeCheckbox::checkState
        \brief This property holds the state of the QSwipeCheckbox.

        \note Any QSwipeCheckox can only be either checked (\c{true})or unchecked (\{false}). A tri-state option is \f not supported.
    */

    /*!
        \property QSwipeCheckbox::enabled
        \brief Whether the QSwipeCheckbox is enabled.

        This property's default is true.
    */
    /*!
          \property QSwipeCheckbox::activeSwitchBorderColor()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::inactiveSwitchBorderColor()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::activePaddingColor()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::inactivePaddingColor()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::shadowColor()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::paddingWidth()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::shadowOpacity()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::shadowAngle()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::shadowSize()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::shadowEnabled()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::size()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::checked()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::displayStyle()
        \brief This property...

    */

    /*!
          \property QSwipeCheckbox::clickableArea()
        \brief This property...

    */


    this->setMouseTracking(true);

    m_shadowWidget = new ShadowWidget(this);

    m_shadowWidget->hide();

    m_shadowWidget->setEnabled(false);

    this->initialize();
}


QSwipeCheckbox::~QSwipeCheckbox() {
    this->setMouseTracking(false);
}

QSize QSwipeCheckbox::sizeHint() const
{
    /*!
        \fn QSize sizeHint() const

        Returns the recommended size for the widget.
        \sa size \sa minimumSize \sa minimumSizeHint
    */
    return QSize(64,28);
}

QSize QSwipeCheckbox::minimumSizeHint() const
{
    /*!
        \fn QSize QSwipeCheckbox::minimumSizeHint() const

        This property holds the widget's minimum size.
        \sa sizeHint
    */
    return QSize(42,18);
}

bool QSwipeCheckbox::checkState() const
{
    /*!
        \fn bool QSwipeCheckbox::checkState() const

    */
    return m_checkState;
}

void QSwipeCheckbox::setCheckState(bool state)
{
    /*!
        \fn bool QSwipeCheckbox::checkState() const

    */
    m_checkState = state;
}

void QSwipeCheckbox::setCheckState(Qt::CheckState state)
{
    /*!
        \fn void QSwipeCheckbox::setCheckState(Qt::CheckState state)
        \overload setCheckState(bool);


    */
    if (state == Qt::Checked) {
        this->setChecked(true);
    } else if (state == Qt::Unchecked) {
        this->setChecked(false);
    } else {
        return;
    }
}

void QSwipeCheckbox::setCheckState(int state)
{
    /*!
        \fn void QSwipeCheckbox::setCheckState(int state)
        \overload setCheckState(bool);

    */
    if (state == Qt::Unchecked) {
        this->setChecked(false);
    } else if (state == Qt::Checked) {
        this->setChecked(true);
    } else {
        return;
    }
}

void QSwipeCheckbox::setChecked(bool checked)
{
    /*!
        \fn void QSwipeCheckbox::setChecked(bool checked)


    */
    m_checkState = checked;
    m_initialized = false;
    if (checked == true) {
        m_animationState = 100.00;
    } else {
        m_animationState = 0.00;
    }
    this->repaint();
}

bool QSwipeCheckbox::isChecked() const {
    /*!
        \overload checked(void)

        \sa QSwipeCheckbox::checked()
    */
    return m_checkState;
}

bool QSwipeCheckbox::checked() const
{
    /*!
        \fn bool QSwipeCheckbox::checked(void)


    */
    return m_checkState;
}

void QSwipeCheckbox::setEnabled(bool enabled)
{
    /*!
        \fn void QSwipeCheckbox::setEnabled(bool enabled)


    */
    m_enabled = enabled;
}

bool QSwipeCheckbox::isEnabled() const
{
    /*!
        \overload enabled(void)

        \sa QSwipeCheckbox::enabled()
    */
    return m_enabled;
}

bool QSwipeCheckbox::enabled() const
{
    /*!
        \fn bool QSwipeCheckbox::enabled(void) const


    */
    return m_enabled;
}

void QSwipeCheckbox::setActiveText(QString str) {
    /*!
        \fn void QSwipeCheckbox::setActiveText(QString text)


    */
    m_activeText = str;
}

void QSwipeCheckbox::setInactiveText(QString str) {
    /*!
        \fn void QSwipeCheckbox::setInactiveText(QString text)


    */
    m_inactiveText = str;
}

void QSwipeCheckbox::setBorderWidth(int width)
{
    /*!
        \fn void QSwipeCheckbox::setBorderWidth(int width = 1)


    */
    if (width >= 0) {
        m_borderWidth = width;
    }
}

int QSwipeCheckbox::paddingWidth() const
{
    /*!
        \fn int QSwipeCheckbox::paddingWidth(void) const


    */
    return m_paddingWidth;
}

void QSwipeCheckbox::setPaddingWidth(int width)
{
    /*!
        \fn void QSwipeCheckbox::setBorderWidth(int width = 1)


    */
    if (width >= 0) {
        m_paddingWidth = width;
    }

}

int QSwipeCheckbox::switchKnobSize() const
{
    /*!
        \fn int QSwipeCheckbox::switchKnobSize(void) const


    */
    return m_switchKnobSize;
}

void QSwipeCheckbox::setSwitchKnobSize(int diameter)
{
    /*!
        \fn void QSwipeCheckbox::setSwitchKnobSize(int diameter = 18)


    */
    if (diameter > 0) {
        m_switchKnobSize = diameter;
    }
}

QString QSwipeCheckbox::activeText(void) const {
    /*!
        \fn QString QSwipeCheckbox::activeText(void) const


    */
    return m_activeText;
}

QString QSwipeCheckbox::inactiveText(void) const {
    /*!
        \fn QString QSwipeCheckbox::inactiveText(void) const


    */
    return m_inactiveText;
}

int QSwipeCheckbox::borderWidth() const
{
    /*!
        \fn int QSwipeCheckbox::borderWidth(void) const


    */
    return m_borderWidth;
}

void QSwipeCheckbox::setActiveBackgroundColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setActiveBackgroundColor(QColor color)


    */
    if (color.isValid()) {
        m_activeBackgroundColor = color;
        resetColors();
    }

}

void QSwipeCheckbox::setInactiveBackgroundColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setInactiveBackgroundColor(QColor color)


    */
    if (color.isValid()) {
        m_inactiveBackgroundColor = color;
        resetColors();
    }
}

void QSwipeCheckbox::setActiveTextColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setActiveTextColor(QColor color)


    */
    if (color.isValid()) {
        m_activeTextColor = color;
        resetColors();
    }
}

void QSwipeCheckbox::setInactiveTextColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setInactiveTextColor(QColor color)


    */
    if (color.isValid()) {
        m_inactiveTextColor = color;
        resetColors();
    }
}

void QSwipeCheckbox::setActiveBorderColor(QColor color) {
    /*!
        \fn void QSwipeCheckbox::setActiveBorderColor(QColor color)


    */
    if (color.isValid()) {
        m_activeBorderColor =  color;
        resetColors();
    }
}

void QSwipeCheckbox::setInactiveBorderColor(QColor color) {
    /*!
        \fn void QSwipeCheckbox::setInactiveBorderColor(QColor color)


    */
    if (color.isValid()) {
        m_inactiveBorderColor =  color;
        resetColors();
    }
}

void QSwipeCheckbox::setActiveSwitchBorderColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setActiveSwitchBorderColor(QColor color)


    */
    if (color.isValid()) {
        m_activeSwitchBorderColor =  color;
        resetColors();
    }
}

void QSwipeCheckbox::setInactiveSwitchBorderColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setInactiveSwitchBorderColor(QColor color)


    */
    if (color.isValid()) {
        m_inactiveSwitchBorderColor =  color;
        resetColors();
    }
}

void QSwipeCheckbox::setInactiveSwitchKnobColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setInactiveSwitchKnobColor(QColor color)


    */
    if (color.isValid()) {
        m_inactiveSwitchKnobColor = color;
        resetColors();
    }
}

void QSwipeCheckbox::setActivePaddingColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setActivePaddingColor(QColor color)


    */
    if (color.isValid()) {
        m_activePaddingColor = color;
        resetColors();
    }
}

void QSwipeCheckbox::setInactivePaddingColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setInactivePaddingColor(QColor color)


    */
    if (color.isValid()) {
        m_inactivePaddingColor = color;
        resetColors();
    }
}

void QSwipeCheckbox::setShadowColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setShadowColor(QColor color)


    */
    if (color.isValid()) {
        m_shadowColor = color;
    }
}

void QSwipeCheckbox::setBackgroundColors(QColor active, QColor inactive)
{
    /*!
        \fn void QSwipeCheckbox::setBackgroundColors(QColor active, QColor inactive)

        \sa setActiveBackgroundColor() \sa setInactiveBackgroundColor()
    */
    if (active.isValid()) {
        m_activeBackgroundColor = active;
    }
    if (inactive.isValid()) {
        m_inactiveBackgroundColor = inactive;
    }
    if (active.isValid() or inactive.isValid()) {
        resetColors();
    }
}

void QSwipeCheckbox::setTextColors(QColor active, QColor inactive)
{
    /*!
        \fn void QSwipeCheckbox::setTextColors(QColor active, QColor inactive)

        \sa setActiveTextColor() \sa setInactiveTextColor()
    */
    if (active.isValid()) {
        m_activeTextColor = active;
    }
    if (inactive.isValid()) {
        m_inactiveTextColor = inactive;
    }
    if (active.isValid() or inactive.isValid()) {
        resetColors();
    }
}

void QSwipeCheckbox::setBorderColors(QColor active, QColor inactive)
{
    /*!
        \fn void QSwipeCheckbox::setBorderColors(QColor active, QColor inactive)

        \sa setActiveBorderColor() \sa setInactiveBorderColor()
    */
    if (active.isValid()) {
        m_activeBorderColor = active;
    }
    if (inactive.isValid()) {
        m_inactiveBorderColor = inactive;
    }
    if (active.isValid() or inactive.isValid()) {
        resetColors();
    }
}

void QSwipeCheckbox::setSwitchBorderColors(QColor active, QColor inactive)
{
    /*!
        \fn void QSwipeCheckbox::setSwitchKnobBorderColors(QColor active, QColor inactive)

        \sa setActiveSwitchBorderColor() \sa setInactiveSwitchBorderColor()
    */
    if (active.isValid()) {
        m_activeSwitchBorderColor = active;
    }
    if (inactive.isValid()) {
        m_inactiveSwitchBorderColor = inactive;
    }
    if (active.isValid() or inactive.isValid()) {
        resetColors();
    }
}

void QSwipeCheckbox::setSwitchKnobColors(QColor active, QColor inactive)
{
    /*!
        \fn void QSwipeCheckbox::setSwitchKnobColors(QColor active, QColor inactive)

        \sa setActiveSwitchKnobColor() \sa setInactiveSwitchKnobColor()
    */
    if (active.isValid()) {
        m_activeSwitchKnobColor = active;
    }
    if (inactive.isValid()) {
        m_inactiveSwitchKnobColor = inactive;
    }
    if (active.isValid() or inactive.isValid()) {
        resetColors();
    }
}

void QSwipeCheckbox::setPaddingColors(QColor active, QColor inactive)
{
    /*!
        \fn void QSwipeCheckbox::setPaddingColors(QColor active, QColor inactive)


        \sa setActivePaddingColor() \sa setInactivePaddingColor()
    */
    if (active.isValid()) {
        m_activePaddingColor = active;
    }
    if (inactive.isValid()) {
        m_inactivePaddingColor = inactive;
    }
    if (active.isValid() or inactive.isValid()) {
        resetColors();
    }
}

void QSwipeCheckbox::setRenderBackgroundColor(QColor color)
{
    m_renderBackgroundColor = color;
}

void QSwipeCheckbox::setRenderKnobColor(QColor color)
{
    m_renderKnobColor = color;
}

void QSwipeCheckbox::setRenderKnobBorderColor(QColor color)
{
    m_renderKnobBorderColor = color;
}

void QSwipeCheckbox::setRenderBorderColor(QColor color)
{
    m_renderBorderColor = color;
}

void QSwipeCheckbox::setRenderPaddingColor(QColor color)
{
    m_renderPaddingColor = color;
}

void QSwipeCheckbox::setActiveSwitchKnobColor(QColor color)
{
    /*!
        \fn void QSwipeCheckbox::setActiveSwitchKnobColor(QColor color)


    */
    if (color.isValid()) {
        m_activeSwitchKnobColor = color;
        resetColors();
    }
}

QColor QSwipeCheckbox::getActiveBackgroundColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getActiveBackgroundColor(void) const


    */
    return m_activeBackgroundColor;
}

QColor QSwipeCheckbox::getActiveTextColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getActiveTextColor(void) const


    */
    return m_activeTextColor;
}

QColor QSwipeCheckbox::getInactiveBackgroundColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getInactiveBackgroundColor(void) const


    */
    return m_inactiveBackgroundColor;
}

QColor QSwipeCheckbox::getInactiveTextColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getInactiveTextColor(void) const


    */
    return m_inactiveTextColor;
}

QColor QSwipeCheckbox::getActiveBorderColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getActiveBorderColor(void) const


    */
    return m_activeBorderColor;
}

QColor QSwipeCheckbox::getInactiveBorderColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getInactiveBorderColor(void) const


    */
    return m_inactiveBorderColor;
}

QColor QSwipeCheckbox::getActiveSwitchBorderColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getActiveSwitchBorderColor(void) const


    */
    return m_activeSwitchBorderColor;
}

QColor QSwipeCheckbox::getInactiveSwitchBorderColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getInactiveSwitchBorderColor(void) const


    */
    return m_inactiveSwitchBorderColor;
}

QColor QSwipeCheckbox::getActiveSwitchKnobColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getActiveSwitchKnobColor(void) const


    */
    return m_activeSwitchKnobColor;
}

QColor QSwipeCheckbox::getInactiveSwitchKnobColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getInactiveSwitchKnobColor(void) const


    */
    return m_inactiveSwitchKnobColor;
}

QColor QSwipeCheckbox::getActivePaddingColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getActivePaddingColor(void) const


    */
    return m_activePaddingColor;
}

QColor QSwipeCheckbox::getInactivePaddingColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getInactivePaddingColor(void) const


    */
    return m_inactivePaddingColor;
}

QColor QSwipeCheckbox::getShadowColor() const
{
    /*!
        \fn QColor QSwipeCheckbox::getShadowColor(void) const


    */
    return m_shadowColor;
}

QColor QSwipeCheckbox::renderBackgroundColor() const
{
    return m_renderBackgroundColor;
}

QColor QSwipeCheckbox::renderKnobColor() const
{
    return m_renderKnobColor;
}

QColor QSwipeCheckbox::renderBorderColor() const
{
    return m_renderBorderColor;
}

QColor QSwipeCheckbox::renderKnobBorderColor() const
{
    return m_renderKnobBorderColor;
}

QColor QSwipeCheckbox::renderPaddingColor() const
{
    return m_renderPaddingColor;
}

void QSwipeCheckbox::setAnimationSpeed(int milliseconds) {
    /*!
        \fn void QSwipeCheckbox::setAnimationSpeed(int milliseconds = 330)


    */
    if (milliseconds >= 0) {
        m_animationSpeed = milliseconds;
    }
}

QFont QSwipeCheckbox::activeTextFont() const
{
    /*!
        \fn QFont QSwipeCheckbox::activeTextFont(void) const


    */
    return m_activeTextFont;
}

QFont QSwipeCheckbox::inactiveTextFont() const
{
    /*!
        \fn QFont QSwipeCheckbox::inactiveTextFont(void) const


    */
    return m_inactiveTextFont;
}

void QSwipeCheckbox::setActiveTextFont(const QFont &font)
{
    /*!
        \fn void QSwipeCheckbox::setActiveTextFont(const QFont &font)


    */
    m_activeTextFont = font;
}

void QSwipeCheckbox::setInactiveTextFont(const QFont &font)
{
    /*!
        \fn void QSwipeCheckbox::setInactiveTextFont(const QFont &font)


    */
    m_inactiveTextFont = font;
}

void QSwipeCheckbox::setWidth(int width)
{
    /*!
        \fn void QSwipeCheckbox::setWidth(int width)


    */
    if (width > minimumSizeHint().width()) {
        m_size.setWidth(width);
    }
}

void QSwipeCheckbox::setHeight(int height)
{
    /*!
        \fn void QSwipeCheckbox::setHeight(int height)


    */
    if (height > minimumSizeHint().height()) {
        m_size.setHeight(height);
    }
}

void QSwipeCheckbox::setSize(int width, int height)
{
    /*!
        \fn void QSwipeCheckbox::setSize(int width, int height)
        \overload setSize(QSize)

    */
    if (width > minimumSizeHint().width() && height > minimumSizeHint().height()) {
        m_size.setWidth(width);
        m_size.setHeight(height);
    }
}

void QSwipeCheckbox::setSize(const QSize &size)
{
    /*!
        \fn void QSwipeCheckbox::setSize(const QSize &size)

        Set the desired Widget size.
        \sa getSize
    */
    if (size.width() > 0 && size.height() > 0) {
        m_size.setWidth(size.width());
        m_size.setHeight(size.height());
    }
}

QSize QSwipeCheckbox::getSize() const
{
    /*!
        \fn QSize QSwipeCheckbox::getSize(void) const

        This property holds the size of the Widget.
    */
    return m_size;
}


int QSwipeCheckbox::animationSpeed() const
{
    /*!
        \fn int QSwipeCheckbox::animationSpeed(void) const

        Returns the speed (duration) of the animation.

        \sa setAnimationSpeed
    */
    return m_animationSpeed;
}

bool QSwipeCheckbox::isAnimationRunning() const
{
    /*!
        \fn bool QSwipeCheckbox::isAnimationRunning(void) const

        This property holds whether there are currently active animations.
    */
    return m_animationIsRunning;
}

QSwipeCheckbox::DisplayStyle QSwipeCheckbox::getDisplayStyle() const
{
    /*!
        \fn QSwipeCheckbox::DisplayStyle QSwipeCheckbox::getDisplayStyle(void) const

        This function returns current the DisplayStyle.
    */
    return m_displayStyle;
}

QString QSwipeCheckbox::getDisplayStyleName() const
{
    /*!
        \fn QString QSwipeCheckbox::getDisplayStyleName(void) const

        This function returns a QString-value containing the DisplayStyle name.
    */
    if (m_displayStyle == DisplayStyle::Classic) {
        return QStringLiteral("DisplayStyle::Classic");
    } else if (m_displayStyle == DisplayStyle::iOS) {
        return QStringLiteral("DisplayStyle::iOS");
    } else if (m_displayStyle == DisplayStyle::Material) {
        return QStringLiteral("DisplayStyle::Material");
    } else if (m_displayStyle == DisplayStyle::Windows) {
        return QStringLiteral("DisplayStyle::Windows");
    }
    return QStringLiteral();
}

void QSwipeCheckbox::setDisplayStyle(DisplayStyle style)
{
    /*!
        \fn void QSwipeCheckbox::setDisplayStyle(DisplayStyle style)

        This function sets the DisplayStyle for the widget.

        \sa DisplayStyle
    */
    m_displayStyle = style;
}

void QSwipeCheckbox::setDisplayStyle(QString style)
{
    /*!
        \fn void QSwipeCheckbox::setDisplayStyle(QString style)
        \overload QSwipeCheckbox::setDisplayStyle(DisplayStyle)

        This function sets the DisplayStyle for the widget.

        \sa DisplayStyle \sa QSwipeCheckbox::setDisplayStyle(DisplayStyle)
    */
    if (style == "QSwipeCheckbox::DisplayStyle::Classic" or style == "DisplayStyle::Classic" or style == "Classic") {
        m_displayStyle = DisplayStyle::Classic;
    } else if (style == "QSwipeCheckbox::DisplayStyle::iOS" or style == "DisplayStyle::iOS" or style == "iOS") {
        m_displayStyle = DisplayStyle::iOS;
    } else if (style == "QSwipeCheckbox::DisplayStyle::Material" or style == "DisplayStyle::Material" or style == "Material") {
        m_displayStyle = DisplayStyle::Material;
    } else if (style == "QSwipeCheckbox::DisplayStyle::Windows" or style == "DisplayStyle::Windows" or style == "Windows") {
        m_displayStyle = DisplayStyle::Windows;
    }
}

QSwipeCheckbox::ClickableArea QSwipeCheckbox::getClickableArea() const
{
    /*!
        \fn QSwipeCheckbox::ClickableArea QSwipeCheckbox::getClickableArea(void) const

        This function returns the current setting of which part of the widget is clickable.

        \sa getClickableAreaName() \sa setClickableArea()
    */
    return m_clickableArea;
}

QString QSwipeCheckbox::getClickableAreaName() const
{
    /*!
        \fn QString QSwipeCheckbox::getClickableArea(void) const

        This function returns a QString containing the current setting of which part of the widget reacts to mouse events.

        \sa getClickableArea() \sa setClickableArea()
    */
    if (m_clickableArea == ClickableArea::Full) {
        return QStringLiteral("ClickableArea::Full");
    } else if (m_clickableArea == ClickableArea::Handle) {
        return QStringLiteral("ClickableArea::Handle");
    } else if (m_clickableArea == ClickableArea::Custom) {
        return QStringLiteral("ClickableArea::Custom");
    }
    return QStringLiteral();
}

void QSwipeCheckbox::setClickableArea(QSwipeCheckbox::ClickableArea area)
{
    /*!
        \fn void QSwipeCheckbox::setClickableArea(QSwipeCheckbox::ClickableArea area)

        This function sets the area that reacts to mouse events for the widget.

        \sa ClickableArea \sa setClickableArea(QString)
    */
    m_clickableArea = area;
}

void QSwipeCheckbox::setClickableArea(QString area)
{
    /*!
        \fn void QSwipeCheckbox::setClickableArea(QString area)
        \overload QSwipeCheckbox::setClickableArea(QSwipeCheckbox::ClickableArea)

        This function sets the area that reacts to mouse events for the widget.

        \sa setClickableArea(QSwipeCheckbox::ClickableArea)
    */
    if (area == "QSwipeCheckbox::ClickableArea::Full" or area == "ClickableArea::Full" or area == "Full") {
        m_clickableArea = ClickableArea::Full;
    } else if (area == "QSwipeCheckbox::ClickableArea::Handle" or area == "ClickableArea::Handle" or area == "Handle") {
        m_clickableArea = ClickableArea::Handle;
    } else if (area == "QSwipeCheckbox::ClickableArea::Custom" or area == "ClickableArea::Custom" or area == "Custom") {
        m_clickableArea = ClickableArea::Custom;
    }
}

QPainterPath QSwipeCheckbox::customClickableArea() const
{
    /*!
        \fn QPainterPath QSwipeCheckbox::customClickableArea() const

        This function returns the QPainterPath which contains the area within the widget that reacts to mouse events.
        \sa setCustomClickableArea()
    */
    return m_customMouseRegion;
}

void QSwipeCheckbox::setCustomClickableArea(QPainterPath &ppath)
{
    /*!
        \fn void QSwipeCheckbox::setCustomClickableArea(QPainterPath &ppath)

        This function sets the QPainterPath containing the area within the widget supposed to react to mouse events.
        \sa customClickableArea()
    */
    if (!ppath.isEmpty()) {
        m_customMouseRegion = ppath;
        this->repaint();
    }
}

int QSwipeCheckbox::shadowOpacity() const
{
    /*!
      \fn int QSwipeCheckbox::shadowOpacity() const

      This function returns the shadow opacity.

      \sa setShadowOpacity(int)
    */
    return m_shadowOpacity;
}

void QSwipeCheckbox::setShadowOpacity(int opacity)
{
    /*!
      \fn void QSwipeCheckbox::setShadowOpacity(int opacity)

      This function sets the shadow opacity (range from 0 \i{transparent} to 100 \i{opaque}).

      \sa shadowOpacity()
    */
    if (opacity >= 100) {
        m_shadowOpacity = 100;
    } else if (opacity <= 0) {
        m_shadowOpacity = 0;
    } else {
        m_shadowOpacity = opacity;
    }
}

int QSwipeCheckbox::getShadowSize() const
{
    /*!
      \fn int QSwipeCheckbox::getShadowSize() const

      This function returns the shadow size.

      \sa setShadowSize(int)
    */
    return m_shadowSize;
}

void QSwipeCheckbox::setShadowSize(int size)
{
    /*!
      \fn void QSwipeCheckbox::setShadowSize(int size)

      This function sets the shadow size in pixels.

      \sa getShadowSize()
    */
    if (size > 0) {
        m_shadowSize = size;
    } else if (size == 0) {
        this->setShadowEnabled(false);
    }
}

int QSwipeCheckbox::getShadowAngle() const
{
    /*!
      \fn int QSwipeCheckbox::getShadowAngle() const

      This function returns the angle of the shadow effect.

      \sa setShadowAngle(int)
    */
    return m_shadowAngle;
}

void QSwipeCheckbox::setShadowAngle(int angle)
{
    /*!
      \fn void QSwipeCheckbox::setShadowAngle(int angle)

      This function sets the shadow angle in degrees (range from 0 to 360) where 0 equals the 12-o'clock position.

      \sa getShadowAngle()
    */
    if (angle > 359) {
        m_shadowAngle = angle % 360;
    } else if (angle < -359) {
        m_shadowAngle = 360 - (qAbs(angle) % 360 );
    } else if (angle < 0) {
        m_shadowAngle = 360 - qAbs(angle);
    } else {
        m_shadowAngle = angle;
    }
}

bool QSwipeCheckbox::shadowEnabled() const
{
    /*!
      \fn bool QSwipeCheckbox::shadowEnabled() const

      This function returns whether the shadow effect is enabled.

      \sa setShadowEnabled(bool)
    */
    return m_shadowEnabled;
}

void QSwipeCheckbox::setShadowEnabled(bool enabled)
{
    /*!
      \fn void QSwipeCheckbox::setShadowEnabled(bool enabled)

      This function enables or disables the shadow effect.

      \sa shadowEnabled()
    */
    m_shadowEnabled = enabled;
    if (enabled) { this->getShadowOffsets(); m_shadowWidget->show(); } else { m_shadowWidget->hide(); }
    this->repaint();
}

#ifdef QT_DEBUG
void QSwipeCheckbox::visualizeCustomMouseRegion(bool enable, QColor color)
{
    /*!
      \fn void QSwipeCheckbox::visualizeCustomMouseRegion(bool enable, QColor color)

      This function enables or disables the rendering of a custom region (set via \f{setClickableArea}) for debugging purposes and sets the color in which the area is being highlighted.
      \note This function is purposely included in \b{debug}-releases only.

      \sa setClickableArea()
    */
    m_visualizeCustomMouseRegion = enable;
    if (m_visualizeCustomMouseRegion) {
        if (color.isValid()) {
          m_visualizeCustomMouseRegion = true;
          m_visualizeCustomMouseRegionColor = color;
        } else {
          m_visualizeCustomMouseRegion = false;
        }
    }
}
#endif

void QSwipeCheckbox::initialize()
{
    if (m_checkState == false) {
        m_renderBorderColor = m_inactiveBorderColor;
        m_renderPaddingColor = m_inactivePaddingColor;
        m_renderBackgroundColor = m_inactiveBackgroundColor;
        m_renderKnobColor = m_inactiveSwitchKnobColor;
        m_renderKnobBorderColor = m_inactiveSwitchBorderColor;
    } else {
        m_renderBorderColor = m_activeBorderColor;
        m_renderPaddingColor = m_activePaddingColor;
        m_renderBackgroundColor = m_activeBackgroundColor;
        m_renderKnobColor = m_activeSwitchKnobColor;
        m_renderKnobBorderColor = m_activeSwitchBorderColor;
    }
    getShadowOffsets();
    m_initialized = true;
}

bool QSwipeCheckbox::isInitialized() const
{
    return m_initialized;
}

void QSwipeCheckbox::runAnimation()
{
    if (m_animationIsRunning) {
        return;
    }
    m_animationIsRunning = true;

    QParallelAnimationGroup *animationGroup = new QParallelAnimationGroup;

    QPropertyAnimation *toggleAnimation = new QPropertyAnimation(this, "animationState");
    QPropertyAnimation *backgroundAnimation = new QPropertyAnimation(this, "renderBackgroundColor");
    QPropertyAnimation *borderAnimation = new QPropertyAnimation(this, "renderBorderColor");
    QPropertyAnimation *knobAnimation = new QPropertyAnimation(this, "renderKnobColor");
    QPropertyAnimation *knobBorderAnimation = new QPropertyAnimation(this, "renderKnobBorderColor");
    QPropertyAnimation *paddingAnimation = new QPropertyAnimation(this, "renderPaddingColor");

    toggleAnimation->setStartValue(0.0);
    toggleAnimation->setEndValue(100.0);

    backgroundAnimation->setStartValue(m_inactiveBackgroundColor);
    backgroundAnimation->setEndValue(m_activeBackgroundColor);
    knobAnimation->setStartValue(m_inactiveSwitchKnobColor);
    knobAnimation->setEndValue(m_activeSwitchKnobColor);
    borderAnimation->setStartValue(m_inactiveBorderColor);
    borderAnimation->setEndValue(m_activeBorderColor);
    knobBorderAnimation->setStartValue(m_inactiveSwitchBorderColor);
    knobBorderAnimation->setEndValue(m_activeSwitchBorderColor);
    paddingAnimation->setStartValue(m_inactivePaddingColor);
    paddingAnimation->setEndValue(m_activePaddingColor);


    toggleAnimation->setDuration(m_animationSpeed);
    backgroundAnimation->setDuration(m_animationSpeed);
    knobAnimation->setDuration(m_animationSpeed);
    knobBorderAnimation->setDuration(m_animationSpeed);
    borderAnimation->setDuration(m_animationSpeed);
    paddingAnimation->setDuration(m_animationSpeed);

    if (m_checkState) {
        animationGroup->setDirection(QAbstractAnimation::Forward);
    } else {
        animationGroup->setDirection(QAbstractAnimation::Backward);
    }

    this->connect(animationGroup, &QAbstractAnimation::finished, [this] () {
        animationStopped();
    });

    animationGroup->addAnimation(toggleAnimation);
    animationGroup->addAnimation(backgroundAnimation);
    animationGroup->addAnimation(knobAnimation);
    animationGroup->addAnimation(knobBorderAnimation);
    animationGroup->addAnimation(borderAnimation);
    animationGroup->addAnimation(paddingAnimation);

    emit animationStarted();

    animationGroup->start();
}

float QSwipeCheckbox::animationState() const
{
    return m_animationState;
}

void QSwipeCheckbox::setAnimationState(float state)
{
    m_animationState = state;
    this->update();
}

void QSwipeCheckbox::paintEvent(QPaintEvent *)
{
    if (!m_initialized) {
        this->initialize();
    }

    QPainter p(this);

    if (m_displayStyle == DisplayStyle::Windows) {
        p.setRenderHints(QPainter::TextAntialiasing|QPainter::SmoothPixmapTransform, true);
    } else {
        p.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform, true);
    }

    if (m_displayStyle == DisplayStyle::Windows or m_displayStyle == DisplayStyle::Classic) {
        m_shadowWidget->hide();
    }

    QPainterPath scene;
    scene.addRect(0,0,this->width(),this->height());
    QPainterPath mask;

    mask.setFillRule(Qt::WindingFill);

    QPainterPath borderPath;
    QPainterPath innerFillPath;

    p.setPen(QPen(QColor(m_renderBorderColor), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    p.setBrush(QColor(m_renderBorderColor));

    switch (m_displayStyle) {

    // ---------- DisplayStyle::Classic ---------- //


    // ---------- DisplayStyle::iOS ---------- //

    case DisplayStyle::iOS:
    case DisplayStyle::Classic: {


        QRect maskEllipse1;
        QRect maskEllipse2;
        QRect maskIntersection;

        int vcenter = m_widgetRadius;

        maskEllipse1.setRect(0,0,m_widgetDiameter,m_widgetDiameter);
        maskEllipse1.moveCenter(QPoint(m_leftPosition,vcenter));

        maskEllipse2.setRect(0,0,m_widgetDiameter,m_widgetDiameter);
        maskEllipse2.moveCenter(QPoint(m_rightPosition,vcenter));

        maskIntersection.setTopLeft(QPoint(m_leftPosition,1));
        maskIntersection.setBottomRight(QPoint(m_rightPosition,m_widgetDiameter));

        mask.addEllipse(maskEllipse1);
        mask.addEllipse(maskEllipse2);
        mask.addRect(maskIntersection);

        mask = scene.intersected(mask);

        p.setClipPath(mask);

        borderPath.moveTo(QPoint(m_rightPosition,1));
        borderPath.arcTo(QRect(m_rightPosition-m_widgetRadius+1,1,m_widgetDiameter,m_widgetDiameter), 90, -180);
        borderPath.arcTo(QRect(1,1,m_widgetDiameter,m_widgetDiameter),-90,-180);
        borderPath.closeSubpath();

        p.drawPath(borderPath);

        innerFillPath.moveTo(QPoint(m_rightPosition,1+m_borderWidth));
        innerFillPath.arcTo(QRect(m_rightPosition-m_widgetRadius+1+m_borderWidth,1+m_borderWidth,m_widgetDiameter-m_borderWidth-m_borderWidth,m_widgetDiameter-m_borderWidth-m_borderWidth), 90, -180);
        innerFillPath.arcTo(QRect(1+m_borderWidth,1+m_borderWidth,m_widgetDiameter-m_borderWidth-m_borderWidth,m_widgetDiameter-m_borderWidth-m_borderWidth), -90, -180);
        innerFillPath.closeSubpath();

        if (m_animationIsRunning) {
            p.setPen(m_renderBackgroundColor);
            p.setBrush(m_renderBackgroundColor);
        } else {
            if (m_checkState == Qt::Unchecked) {
                p.setPen(m_inactiveBackgroundColor);
                p.setBrush(m_inactiveBackgroundColor);
            } else {
                p.setPen(m_activeBackgroundColor);
                p.setBrush(m_activeBackgroundColor);
            }
        }

        if (!m_animationIsRunning) {
            if (m_clickableArea == ClickableArea::Full) {
                m_mouseHoverRect = QRect(0,0,m_widgetSize.width(),m_widgetSize.height());
                m_mouseHoverRegion.clear();
                m_mouseHoverRegion.addPath(mask);
            }
            if (m_clickableArea == ClickableArea::Handle) {
                if (m_checkState == Qt::Unchecked) {
                    m_mouseHoverRect = QRect(1+m_borderWidth,1+m_borderWidth,m_widgetDiameter-m_borderWidth-m_borderWidth,m_widgetDiameter-m_borderWidth-m_borderWidth);
                    m_mouseHoverRegion.clear();
                    m_mouseHoverRegion.addEllipse(m_mouseHoverRect);
                } else {
                    m_mouseHoverRect = QRect(m_rightPosition-m_widgetRadius+1+m_borderWidth,1+m_borderWidth,m_widgetDiameter-m_borderWidth-m_borderWidth,m_widgetDiameter-m_borderWidth-m_borderWidth);
                    m_mouseHoverRegion.clear();
                    m_mouseHoverRegion.addEllipse(m_mouseHoverRect);
                }
            }
            if (m_clickableArea == ClickableArea::Custom) {
                m_mouseHoverRect.setTop(m_customMouseRegion.boundingRect().top());
                m_mouseHoverRect.setLeft(m_customMouseRegion.boundingRect().left());
                m_mouseHoverRect.setWidth(m_customMouseRegion.boundingRect().width());
                m_mouseHoverRect.setHeight(m_customMouseRegion.boundingRect().height());
                m_mouseHoverRegion.clear();
                m_mouseHoverRegion = m_customMouseRegion;
            }
        }

        p.drawPath(innerFillPath);

        p.setPen(m_renderBorderColor);
        p.setBrush(m_renderBorderColor);

        if (m_displayStyle == DisplayStyle::Classic) {
            paintClassicStyleSwitchElements(p, innerFillPath);
        } else {
            paintiOSStyleSwitchElements(p, innerFillPath);
        }

    };
    break;

    // ---------- DisplayStyle::Material ---------- //

    case DisplayStyle::Material: {

        QRect maskRect;

        maskRect.setRect(m_borderWidth,m_borderWidth,m_widgetSize.width()-m_borderWidth-m_borderWidth,m_widgetSize.height()-m_borderWidth-m_borderWidth);

        mask.addRect(maskRect);

        if (!m_animationIsRunning) {
            if (m_clickableArea == ClickableArea::Full) {
                m_mouseHoverRect = maskRect;
                m_mouseHoverRegion.clear();
                m_mouseHoverRegion.addPath(mask);
            }
            if (m_clickableArea == ClickableArea::Handle) {
                if (m_checkState == Qt::Unchecked) {
                    m_mouseHoverRect = m_knobRect;
                    m_mouseHoverRegion.clear();
                    m_mouseHoverRegion.addEllipse(m_mouseHoverRect);
                } else {
                    m_mouseHoverRect = m_knobRect.translated(m_rightPosition-m_leftPosition,0);
                    m_mouseHoverRegion.clear();
                    m_mouseHoverRegion.addEllipse(m_mouseHoverRect);
                }
            }
            if (m_clickableArea == ClickableArea::Custom) {
                m_mouseHoverRect.setTop(m_customMouseRegion.boundingRect().top());
                m_mouseHoverRect.setLeft(m_customMouseRegion.boundingRect().left());
                m_mouseHoverRect.setWidth(m_customMouseRegion.boundingRect().width());
                m_mouseHoverRect.setHeight(m_customMouseRegion.boundingRect().height());
                m_mouseHoverRegion.clear();
                m_mouseHoverRegion = m_customMouseRegion;
            }
        }

        paintMaterialStyleSwitchElements(p, mask);
    };
    break;

    // ---------- DisplayStyle::Windows ---------- //

    case DisplayStyle::Windows: {

        QRect maskRect;

        maskRect.setRect(0,0,m_widgetSize.width(),m_widgetSize.height());

        mask.addRect(maskRect);

        mask = scene.intersected(mask);

        p.setClipPath(mask);

        borderPath.moveTo(1,1);
        borderPath.lineTo(m_widgetSize.width()-1,1);
        borderPath.lineTo(m_widgetSize.width()-1,m_widgetSize.height()-1);
        borderPath.lineTo(1,m_widgetSize.height()-1);
        borderPath.closeSubpath();

        p.drawPath(borderPath);

        if (!m_animationIsRunning) {
            if (m_clickableArea == ClickableArea::Full) {
                m_mouseHoverRect = maskRect;
                m_mouseHoverRegion.clear();
                m_mouseHoverRegion.addPath(mask);
            }
            if (m_clickableArea == ClickableArea::Handle) {
                if (m_checkState == Qt::Unchecked) {
                    m_mouseHoverRect = m_knobRect;
                    m_mouseHoverRegion.clear();
                    m_mouseHoverRegion.addEllipse(m_mouseHoverRect);
                } else {
                    m_mouseHoverRect = m_knobRect.translated(m_rightPosition,0);
                    m_mouseHoverRegion.clear();
                    m_mouseHoverRegion.addEllipse(m_mouseHoverRect);
                }
            }
            if (m_clickableArea == ClickableArea::Custom) {
                m_mouseHoverRect.setTop(m_customMouseRegion.boundingRect().top());
                m_mouseHoverRect.setLeft(m_customMouseRegion.boundingRect().left());
                m_mouseHoverRect.setWidth(m_customMouseRegion.boundingRect().width());
                m_mouseHoverRect.setHeight(m_customMouseRegion.boundingRect().height());
                m_mouseHoverRegion.clear();
                m_mouseHoverRegion = m_customMouseRegion;
            }
        }

        paintWindowsStyleSwitchElements(p, mask);

    };
    break;

    // ---------- DEFAULT ---------- //

    default: // just in case no style was set...
        this->setDisplayStyle(DisplayStyle::Classic);
        this->repaint();
    }

}

void QSwipeCheckbox::paintClassicStyleSwitchElements(QPainter &p, QPainterPath &clippingPath) {

    float distance = static_cast<float>(m_rightPosition) - static_cast<float>(m_leftPosition);

    float offset = ( distance / 100.00 * m_animationState );

    float knobPosition = static_cast<float>(m_leftPosition) + offset;

    QPainterPath activeTextClipping;
    QPainterPath inactiveTextClipping;

    QPainterPath fontMask;

    QPainterPath fontKnobMask;
    fontKnobMask.addEllipse(m_knobRect.translated(offset,0));

    float vcenter = static_cast<float>(m_widgetRadius);

    p.setPen(m_renderKnobBorderColor);
    p.setBrush(m_renderKnobBorderColor);

    QRectF knobEllipseBorder;
    knobEllipseBorder.setRect(0,0,m_switchKnobSize,m_switchKnobSize);
    knobEllipseBorder.moveCenter(QPointF(knobPosition+1,vcenter+1));

    p.drawEllipse(knobEllipseBorder);

    p.setPen(m_renderKnobColor);
    p.setBrush(m_renderKnobColor);

    int innerKnobSize = m_switchKnobSize - m_borderWidth - m_borderWidth;

    QRectF innerKnobEllipse;
    innerKnobEllipse.setRect(0,0,innerKnobSize,innerKnobSize);
    innerKnobEllipse.moveCenter(QPointF(knobPosition+1,vcenter+1));

    p.drawEllipse(innerKnobEllipse);

    fontMask.setFillRule(Qt::WindingFill);

    fontMask = clippingPath;

    fontMask = fontMask.subtracted(fontKnobMask);

    p.setClipPath(fontMask);

    QRect inactiveTextRect;


    p.setPen(m_inactiveTextColor);
    p.setBrush(m_inactiveTextColor);
    p.setFont(m_inactiveTextFont);
    inactiveTextRect.setRect(1+m_widgetDiameter-m_borderWidth,1+m_borderWidth,m_rightPosition-m_widgetRadius,m_widgetDiameter-m_borderWidth-m_borderWidth);
    inactiveTextRect.translate(offset,0);
    p.drawText(inactiveTextRect, Qt::AlignCenter, m_inactiveText);

    p.setClipPath(fontMask);

    QRect activeTextRect;


    p.setPen(m_activeTextColor);
    p.setBrush(m_activeTextColor);
    p.setFont(m_activeTextFont);
    activeTextRect.setRect(1+m_borderWidth-distance,1+m_borderWidth,m_rightPosition-m_widgetRadius,m_widgetDiameter-m_borderWidth-m_borderWidth);
    activeTextRect.translate(offset,0);
    p.drawText(activeTextRect, Qt::AlignCenter, m_activeText);

#ifdef QT_QML_DEBUG
    if (m_visualizeCustomMouseRegion) {
        if (m_visualizeCustomMouseRegionColor.isValid()) {
            p.setPen(m_visualizeCustomMouseRegionColor);
            p.setBrush(m_visualizeCustomMouseRegionColor);
            p.drawPath(m_customMouseRegion);
        }
    }
#endif
}

void QSwipeCheckbox::paintiOSStyleSwitchElements(QPainter &p, QPainterPath &clippingPath) {

    std::ignore = clippingPath;

    float distance = static_cast<float>(m_rightPosition) - static_cast<float>(m_leftPosition);

    float offset = ( distance / 100.00 * m_animationState );

    float knobPosition = static_cast<float>(m_leftPosition) + offset;

    QPainterPath activeTextClipping;
    QPainterPath inactiveTextClipping;

    QPainterPath fontMask;

    float vcenter = static_cast<float>(m_widgetRadius);

    p.setPen(m_renderBorderColor);
    p.setBrush(m_renderBorderColor);

    int knobSize = m_widgetDiameter;

    QRectF knobEllipseBorder;
    knobEllipseBorder.setRect(0,0,knobSize,knobSize);
    knobEllipseBorder.moveCenter(QPointF(knobPosition+1,vcenter+1));

    p.drawEllipse(knobEllipseBorder);

    p.setPen(m_renderKnobColor);
    p.setBrush(m_renderKnobColor);

    int innerKnobSize = m_widgetDiameter-m_borderWidth-m_borderWidth;

    if (m_shadowEnabled) {

        m_shadowWidget->setGeometry(m_borderWidth+offset+1,m_borderWidth+1,innerKnobSize,innerKnobSize);
        m_shadowWidget->setGradientAColor(m_renderKnobColor);
        m_shadowWidget->setGradientBColor(m_renderKnobColor.darker(108));
        m_shadowWidget->show();

        m_shadowEffect = new QGraphicsDropShadowEffect(this);
        m_shadowEffect->setXOffset(m_shadowPoint.x());
        m_shadowEffect->setYOffset(m_shadowPoint.y());
        if (m_shadowColor.isValid()) {
            if (m_shadowOpacity > 0 and m_shadowOpacity <= 100) {
                m_shadowEffect->setColor(QColor(m_shadowColor.red(),m_shadowColor.green(),m_shadowColor.blue(),(m_shadowOpacity*2.55)));
            } else {
                m_shadowEffect->setColor(QColor(m_shadowColor.red(),m_shadowColor.green(),m_shadowColor.blue()));
            }
        } else {
                m_shadowEffect->setColor(QColor(63, 63, 63, 127));
        }
        m_shadowEffect->setBlurRadius((m_shadowSize>m_borderWidth?m_borderWidth:m_shadowSize));
        m_shadowEffect->setEnabled(true);
        m_shadowWidget->setGraphicsEffect(m_shadowEffect);

    } else {

    m_shadowWidget->hide();

    QRectF innerKnobEllipse;
    innerKnobEllipse.setRect(0,0,innerKnobSize,innerKnobSize);
    innerKnobEllipse.moveCenter(QPointF(knobPosition+1,vcenter+1));

    p.drawEllipse(innerKnobEllipse);

}


#ifdef QT_QML_DEBUG
    if (m_visualizeCustomMouseRegion) {
        if (m_visualizeCustomMouseRegionColor.isValid()) {
            p.setPen(m_visualizeCustomMouseRegionColor);
            p.setBrush(m_visualizeCustomMouseRegionColor);
            p.drawPath(m_customMouseRegion);
        }
    }
#endif

}

void QSwipeCheckbox::paintMaterialStyleSwitchElements(QPainter &p, QPainterPath &clippingPath) {

    std::ignore = clippingPath;

    float distance = static_cast<float>(m_rightPosition) - static_cast<float>(m_leftPosition);

    float offset = ( distance / 100.00 * m_animationState );

    float vcenter = static_cast<float>(m_widgetSize.height()/2);

    p.setPen(m_renderBackgroundColor);
    p.setBrush(m_renderBackgroundColor);

    QPainterPath slideRailPath;

    float innerRadius = m_widgetRadius-m_paddingWidth;

    slideRailPath.moveTo(m_rightPosition+1,vcenter-innerRadius+1);
    slideRailPath.arcTo(QRect(m_rightPosition-innerRadius+1,vcenter-innerRadius+1,innerRadius+innerRadius,innerRadius+innerRadius), 90, -180);
    slideRailPath.lineTo(m_leftPosition,vcenter+innerRadius+1);
    slideRailPath.arcTo(QRect(m_leftPosition-innerRadius+1,vcenter-innerRadius+1,innerRadius+innerRadius,innerRadius+innerRadius), -90, -180);
    slideRailPath.closeSubpath();

    p.drawPath(slideRailPath);

    p.setPen(m_renderKnobColor);
    p.setBrush(m_renderKnobColor);


    if (m_shadowEnabled) {

        m_shadowWidget->setGeometry(m_borderWidth+offset+1,m_borderWidth+1,m_knobRect.width(),m_knobRect.height());
        m_shadowWidget->setForegroundColor(m_renderKnobColor);
        m_shadowWidget->show();

        m_shadowEffect = new QGraphicsDropShadowEffect(this);
        m_shadowEffect->setXOffset(m_shadowPoint.x()*0.5);
        m_shadowEffect->setYOffset(m_shadowPoint.y()*0.5);
        if (m_shadowColor.isValid()) {
            if (m_shadowOpacity > 0 and m_shadowOpacity <= 100) {
                m_shadowEffect->setColor(QColor(m_shadowColor.red(),m_shadowColor.green(),m_shadowColor.blue(),(m_shadowOpacity*2.55)));
            } else {
                m_shadowEffect->setColor(QColor(m_shadowColor.red(),m_shadowColor.green(),m_shadowColor.blue()));
            }
        } else {
                m_shadowEffect->setColor(QColor(63, 63, 63, 127));
        }
        m_shadowEffect->setBlurRadius((m_shadowSize>m_borderWidth?m_borderWidth:m_shadowSize));
        m_shadowEffect->setEnabled(true);
        m_shadowWidget->setGraphicsEffect(m_shadowEffect);

    } else {

        m_shadowWidget->hide();

        QRectF knobEllipse;
        knobEllipse.setRect(0,0,m_knobRect.width(),m_knobRect.height());
        knobEllipse.moveCenter(QPointF(m_leftPosition+offset+1,vcenter+1));

        p.drawEllipse(knobEllipse);

    }


#ifdef QT_QML_DEBUG
    if (m_visualizeCustomMouseRegion) {
        if (m_visualizeCustomMouseRegionColor.isValid()) {
            p.setPen(m_visualizeCustomMouseRegionColor);
            p.setBrush(m_visualizeCustomMouseRegionColor);
            p.drawPath(m_customMouseRegion);
        }
    }
#endif

}

void QSwipeCheckbox::paintWindowsStyleSwitchElements(QPainter &p, QPainterPath &clippingPath) {

    float distance = static_cast<float>(m_rightPosition) - static_cast<float>(m_leftPosition);

    float offset = ( distance / 100.00 * m_animationState );

    QPainterPath fontMask;

    fontMask.setFillRule(Qt::WindingFill);

    p.setPen(m_renderPaddingColor);
    p.setBrush(m_renderPaddingColor);

    QPainterPath paddingRect;
    paddingRect.moveTo(1+m_borderWidth,1+m_borderWidth);
    paddingRect.lineTo(m_widgetSize.width()-m_borderWidth-1,1+m_borderWidth);
    paddingRect.lineTo(m_widgetSize.width()-m_borderWidth-1,m_widgetSize.height()-m_borderWidth-1);
    paddingRect.lineTo(1+m_borderWidth,m_widgetSize.height()-m_borderWidth-1);
    paddingRect.closeSubpath();

    p.drawPath(paddingRect);

    QPainterPath inactiveBg;
    QPainterPath activeBg;
    QPainterPath knobRect;

    knobRect.addRect(m_knobRect);
    knobRect.translate(offset,0);

    QPainterPath bgMask;
    bgMask.moveTo(1+m_borderWidth,1+m_borderWidth);
    bgMask.lineTo(m_widgetSize.width()-m_borderWidth,1+m_borderWidth);
    bgMask.lineTo(m_widgetSize.width()-m_borderWidth,m_widgetSize.height()-m_borderWidth-1);
    bgMask.lineTo(1+m_borderWidth,m_widgetSize.height()-m_borderWidth-1);
    bgMask.closeSubpath();

    p.setClipPath(bgMask);

    p.setPen(m_inactiveBackgroundColor);
    p.setBrush(m_inactiveBackgroundColor);

    inactiveBg.moveTo(m_knobRect.right()-1,1+m_borderWidth+m_paddingWidth);
    inactiveBg.lineTo(m_widgetSize.width()-m_borderWidth-m_paddingWidth-1, 1+m_borderWidth+m_paddingWidth);
    inactiveBg.lineTo(m_widgetSize.width()-m_borderWidth-m_paddingWidth-1, m_widgetSize.height()-m_borderWidth-m_paddingWidth-1);
    inactiveBg.lineTo(m_knobRect.right()-1,m_widgetSize.height()-m_borderWidth-m_paddingWidth-1);
    inactiveBg.closeSubpath();
    inactiveBg.translate(offset,0);

    p.drawPath(inactiveBg);

    p.setPen(m_activeBackgroundColor);
    p.setBrush(m_activeBackgroundColor);

    activeBg.moveTo(m_knobRect.left()+1,1+m_borderWidth+m_paddingWidth);
    activeBg.lineTo(-m_widgetSize.width()+3+m_borderWidth+m_paddingWidth+m_knobRect.width(),1+m_borderWidth+m_paddingWidth);
    activeBg.lineTo(-m_widgetSize.width()+3+m_borderWidth+m_paddingWidth+m_knobRect.width(),m_widgetSize.height()-m_borderWidth-m_paddingWidth-1);
    activeBg.lineTo(m_knobRect.left()+1,m_widgetSize.height()-m_borderWidth-m_paddingWidth-1);
    activeBg.closeSubpath();
    activeBg.translate(offset,0);

    p.drawPath(activeBg);

    fontMask = bgMask;
    QPainterPath fontKnobMask;
    fontKnobMask.addRect(m_knobRect.translated(offset,0));
    fontMask = fontMask.subtracted(fontKnobMask);

    QRect activeTextRect;
    QRect inactiveTextRect;

    QRect activeTextBB;
    QRect inactiveTextBB;

    p.setPen(m_inactiveTextColor);
    p.setBrush(m_inactiveTextColor);
    p.setFont(m_inactiveTextFont);
    inactiveTextRect.setRect(m_knobRect.right()+2,1+m_borderWidth+m_paddingWidth,m_widgetSize.width()-m_borderWidth-m_paddingWidth-m_knobRect.width()-1,m_widgetSize.height()-m_borderWidth-m_paddingWidth-m_borderWidth-m_paddingWidth-1);
    inactiveTextRect.translate(offset,0);
    p.drawText(inactiveTextRect, Qt::AlignCenter, m_inactiveText, &inactiveTextBB);

    p.setPen(m_activeTextColor);
    p.setBrush(m_activeTextColor);
    p.setFont(m_activeTextFont);
    activeTextRect.setRect(-m_widgetSize.width()+3+m_borderWidth+m_paddingWidth+m_knobRect.width(),1+m_borderWidth+m_paddingWidth,m_widgetSize.width()-m_borderWidth-m_paddingWidth-m_knobRect.width()-3,m_widgetSize.height()-m_borderWidth-m_paddingWidth-m_borderWidth-m_paddingWidth-1);
    activeTextRect.translate(offset,0);
    p.drawText(activeTextRect, Qt::AlignCenter, m_activeText, &activeTextBB);

    p.setClipPath(clippingPath);

    p.setPen(m_renderKnobColor);
    p.setBrush(m_renderKnobColor);

    p.drawPath(knobRect);

#ifdef QT_QML_DEBUG
    if (m_visualizeCustomMouseRegion) {
        if (m_visualizeCustomMouseRegionColor.isValid()) {
            p.setPen(m_visualizeCustomMouseRegionColor);
            p.setBrush(m_visualizeCustomMouseRegionColor);
            p.drawPath(m_customMouseRegion);
        }
    }
#endif

}

void QSwipeCheckbox::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mouseHoverRect.isEmpty()) {
        event->accept();
        return;
    }
    if (m_animationIsRunning) {
        event->accept();
        return;
    }
    if (!m_enabled) {
        event->accept();
        return;
    }
    if (m_mouseHoverRegion.contains(event->localPos())) {
        this->setCursor(Qt::PointingHandCursor);
    } else {
        this->setCursor(Qt::ArrowCursor);
    }
    event->accept();
}

void QSwipeCheckbox::mousePressEvent(QMouseEvent *event)
{
    if (m_mouseHoverRect.isEmpty()) {
        event->accept();
        return;
    }
    if (m_animationIsRunning) {
        event->accept();
        return;
    }
    if (!m_enabled) {
        this->setCursor(Qt::ForbiddenCursor);
        event->accept();
        return;
    }
}

void QSwipeCheckbox::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_mouseHoverRect.isEmpty()) {
        event->accept();
        return;
    }
    if (m_animationIsRunning) {
        event->accept();
        return;
    }
    if (!m_enabled) {
        this->setCursor(Qt::ArrowCursor);
        event->accept();
        return;
    }
    if (m_mouseHoverRegion.contains(event->localPos())) {
        if (m_checkState == false) {
            m_checkState = true;
            emit stateChanged(m_checkState);
            this->setCursor(Qt::ArrowCursor);
            this->repaint();
            if(m_animationSpeed > 0) {
                runAnimation();
            }
        } else {
            m_checkState = false;
            emit stateChanged(m_checkState);
            this->setCursor(Qt::ArrowCursor);
            this->repaint();
            if(m_animationSpeed > 0) {
                runAnimation();
            }
        }
    }
    event->accept();
}

void QSwipeCheckbox::resizeEvent(QResizeEvent *event)
{
    int width = this->width()-1;

    if ((width % 2) == 1) {
        width--;
    }

    int height = this->height()-1;

    if ((height % 2) == 1) {
        height--;
    }

    m_widgetSize = QSize(width, height);

    if (m_displayStyle == DisplayStyle::Classic or m_displayStyle == DisplayStyle::iOS) {

        m_widgetDiameter = m_widgetSize.height();

        m_widgetRadius = (m_widgetDiameter / 2);

        m_leftPosition = m_widgetRadius;

        m_rightPosition = m_widgetSize.width() - m_widgetRadius;

        m_knobRect = QRect(1+m_borderWidth,1+m_borderWidth,m_widgetDiameter-m_borderWidth-m_borderWidth,m_widgetDiameter-m_borderWidth-m_borderWidth);

    }
    if (m_displayStyle == DisplayStyle::Material) {

        m_widgetDiameter = m_widgetSize.height()-m_borderWidth-m_borderWidth;

        m_widgetRadius = (m_widgetDiameter / 2);

        m_leftPosition = m_borderWidth+m_widgetRadius;

        m_rightPosition = m_widgetSize.width()-m_borderWidth-m_widgetRadius;

        m_knobRect = QRect(1+m_borderWidth,1+m_borderWidth,m_widgetDiameter,m_widgetDiameter);

    }
    if (m_displayStyle == DisplayStyle::Windows) {

        m_leftPosition = 1;

        m_rightPosition = m_widgetSize.width()-1-m_switchKnobSize;

        m_knobRect = QRect(1, 1, m_switchKnobSize, m_widgetSize.height()-1);

    }

    event->accept();
}

void QSwipeCheckbox::resetColors(void)
{
    m_initialized = false;
    this->repaint();
}

void QSwipeCheckbox::getShadowOffsets()
{
    int x = m_shadowSize * qCos(qDegreesToRadians(static_cast<double>(m_shadowAngle)));
    int y = m_shadowSize * qSin(qDegreesToRadians(static_cast<double>(m_shadowAngle)));

    m_shadowPoint = QPoint(x,y);
}

void QSwipeCheckbox::animationStopped()
{
    m_animationIsRunning = false;
    if (m_mouseHoverRegion.contains(this->mapFromGlobal(QCursor::pos()))) {
        this->setCursor(Qt::PointingHandCursor);
    }
    this->repaint();
    emit animationFinished();
}
