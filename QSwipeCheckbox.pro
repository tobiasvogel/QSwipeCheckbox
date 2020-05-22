CONFIG      += plugin
TEMPLATE    = lib
QT          += widgets uiplugin

HEADERS += \
    qswipecheckbox.h \
    qswipecheckboxdesignerplugin.h

SOURCES += \
    qswipecheckbox.cpp \
    qswipecheckboxdesignerplugin.cpp

exists($$PWD/.git) {
GITREV = $$system(git --git-dir=$PWD/.git rev-parse HEAD)
}

if (win) {
CMDDATA = $$system(wmic os get locatdatetime /value)
STR = $$split(CMDDATA,=)
STR = $$last(STR)
YEAR = $$str_member($$STR,0,3)
MONTH = $$str_member($$STR,4,5)
DAY = $$str_member($$STR,6,7)
HRS = $$str_member($$STR,8,9)
MINS = $$str_member($$STR,10,11)
SECS = $$str_member($$STR,12,13)
DATE = $$YEAR-$$MONTH-$$DAY
TIME = $$HRS-$$MINS-$$SECS
}
if (unix) {
DATE = $$system(date +%Y-%m-%d)
TIME = $$system(date +%H-%M-%S)
}

isEmpty(GITREV) {
    VERSION_STRING = $${DATE}_$${TIME}
} else {
    VERSION_STRING = $${DATE}-git$${GITREV}
}

version_h_data = "$${LITERAL_HASH}ifndef VERSION_H"
version_h_data += "$${LITERAL_HASH}define VERSION_H"
version_h_data += ""
version_h_data += "$${LITERAL_HASH}define VERSION $${VERSION_STRING}"
version_h_data += ""
version_h_data += "$${LITERAL_HASH}endif"

version.target = $${OUT_PWD}/version.h

write_file($$version.target, version_h_data)


target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target

RESOURCES += \
    resources.qrc

QDOCCONFIN = $$cat($${PWD}/docs/QSwipeCheckbox.qdocconf, lines)
for (LINE, QDOCCONFIN) {
LINE = $$replace(LINE, $${LITERAL_HASH}VERSION_STRING$${LITERAL_HASH}, $${VERSION_STRING})
LINE = $$replace(LINE, $${LITERAL_HASH}INPUT_DIR$${LITERAL_HASH}, $${PWD})
LINE = $$replace(LINE, $${LITERAL_HASH}OUTPUT_DIR$${LITERAL_HASH}, $${OUT_PWD}/docs)
LINE = $$replace(LINE, $${LITERAL_HASH}QT_INSTALL_DOCS$${LITERAL_HASH}, $$[QT_INSTALL_DOCS])
QDOCCONFOUT += $$LINE
}

write_file($${OUT_PWD}/docs/QSwipeCheckbox.qdocconf, QDOCCONFOUT)

docs.target = $${OUT_PWD}/docs

QTWIDGETS_INCLUDE = $$system(pkg-config --cflags-only-I Qt5Widgets)
docs.commands = qdoc -I $${PWD} $${QTWIDGETS_INCLUDE} $${OUT_PWD}/docs/QSwipeCheckbox.qdocconf


QMAKE_EXTRA_TARGETS += docs version

PRE_TARGETDEPS += version.h

POST_TARGETDEPS += docs
