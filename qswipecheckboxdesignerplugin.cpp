#include "qswipecheckboxdesignerplugin.h"

QSwipeCheckboxDesignerPlugin::QSwipeCheckboxDesignerPlugin(QObject *parent) : QObject(parent) { }

bool QSwipeCheckboxDesignerPlugin::isContainer() const
{
    return false;
}

bool QSwipeCheckboxDesignerPlugin::isInitialized() const
{
    return initialized;
}

QIcon QSwipeCheckboxDesignerPlugin::icon() const
{
    return QIcon(":/img/icon.png");
}

QString QSwipeCheckboxDesignerPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           "	<widget class=\"QSwipeCheckbox\" name=\"swipeCheckbox\">\n"
           "		<property name=\"geometry\">\n"
           "			<rect>\n"
           "				<x>0</x>\n"
           "				<y>0</y>\n"
           "				<width>64</width>\n"
           "				<height>28</height>\n"
           "			</rect>\n"
           "		</property>\n"
           "		<property name=\"activeBackgroundColor\">\n"
           "			<color>\n"
           "				<red>52</red>\n"
           "				<green>167</green>\n"
           "				<blue>193</blue>\n"
           "			</color>\n"
           "		</property>\n"
           "		<property name=\"inactiveBackgroundColor\">\n"
           "			<color>\n"
           "				<red>238</red>\n"
           "				<green>238</green>\n"
           "				<blue>238</blue>\n"
           "			</color>\n"
           "		</property>\n"
           "		<property name=\"activeTextColor\">\n"
           "			<color>\n"
           "				<red>255</red>\n"
           "				<green>255</green>\n"
           "				<blue>255</blue>\n"
           "			</color>\n"
           "		</property>\n"
           "		<property name=\"inactiveTextColor\">\n"
           "			<color>\n"
           "				<red>153</red>\n"
           "				<green>153</green>\n"
           "				<blue>153</blue>\n"
           "			</color>\n"
           "		</property>\n"
           "		<property name=\"borderColor\">\n"
           "			<color>\n"
           "				<red>153</red>\n"
           "				<green>153</green>\n"
           "				<blue>153</blue>\n"
           "			</color>\n"
           "		</property>\n"
           "		<property name=\"activeSwitchKnobColor\">\n"
           "			<color>\n"
           "				<red>39</red>\n"
           "				<green>161</green>\n"
           "				<blue>202</blue>\n"
           "			</color>\n"
           "		</property>\n"
           "		<property name=\"inactiveSwitchKnobColor\">\n"
           "			<color>\n"
           "				<red>194</red>\n"
           "				<green>194</green>\n"
           "				<blue>194</blue>\n"
           "			</color>\n"
           "		</property>\n"
           "		<property name=\"borderWidth\">\n"
           "			<number>2</number>\n"
           "		</property>\n"
           "		<property name=\"activeText\">\n"
           "			<string>text</string>\n"
           "		</property>\n"
           "		<property name=\"inactiveText\">\n"
           "			<string>text</string>\n"
           "		</property>\n"
           "		<property name=\"switchKnobSize\">\n"
           "			<number>17</number>\n"
           "		</property>\n"
           "		<property name=\"checked\">\n"
           "			<bool>false</bool>\n"
           "		</property>\n"
           "		<property name=\"activeTextFont\">\n"
           "			<font>\n"
           "				<pointsize>12</pointsize>\n"
           "			</font>\n"
           "		</property>\n"
           "		<property name=\"inactiveTextFont\">\n"
           "			<font>\n"
           "				<pointsize>12</pointsize>\n"
           "			</font>\n"
           "		</property>\n"
           "		<property name=\"animationSpeed\">\n"
           "			<number>330</number>\n"
           "		</property>\n"
           "       <property name=\"enabled\">\n"
           "           <bool>true</bool>\n"
           "		</property>\n"
           "       <property name=\"displayStyle\">\n"
           "           <enum>Classic</enum>\n"
           "       </property>\n"
           "       <property name=\"clickableArea\">\n"
           "           <enum>Knob</enum>\n"
           "       </property>\n"
           "	</widget>\n"
           "</ui>\n";
}

QString QSwipeCheckboxDesignerPlugin::group() const
{
    return QStringLiteral("Buttons");
}

QString QSwipeCheckboxDesignerPlugin::includeFile() const
{
    return QStringLiteral("qswipecheckbox.h");
}

QString QSwipeCheckboxDesignerPlugin::name() const
{
    return QStringLiteral("QSwipeCheckbox");
}

QString QSwipeCheckboxDesignerPlugin::toolTip() const
{
    return QString("Flippable-Style Checkbox");
}

QString QSwipeCheckboxDesignerPlugin::whatsThis() const
{
    return QString("Alternative implementation of regular Checkboxes in Swipe-Checkbox Style, a.k.a. Flippable-Checkbox, Flip-Switch, etc.");
}

QWidget *QSwipeCheckboxDesignerPlugin::createWidget(QWidget *parent)
{
    return new QSwipeCheckbox(parent);
}

void QSwipeCheckboxDesignerPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}
