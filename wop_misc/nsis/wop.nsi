# WoP 1.6.0 Installer
# by smiley :)
# smiley@chillerlan.net
# 04.03.2018

# wop.nsi (Windows1252)

!verbose 4

# installer source root
!define SRC "C:\amp\htdocs\wop-installer"

# General definitions
VIProductVersion 1.6.0.0
!define VERSION "1.6.0"
!define PRODUCTNAME "World of Padman"
!define SHORTNAME "wop"
!define FILENAME "${SHORTNAME}-${VERSION}-full.exe"
!define COMPANY "Padworld Entertainment"
!define URL "https://worldofpadman.net"
!define REGKEY "SOFTWARE\${COMPANY}\${PRODUCTNAME} ${VERSION}"
!define UNREGKEY "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCTNAME} ${VERSION}"
!define MUI_ICON "${SRC}\xtras\WoP.ico"
!define MUI_UNICON "${SRC}\xtras\UnWoP.ico"
!define SPLPIC "${SRC}\assets\spltmp.bmp"
!define BGPIC "${SRC}\assets\insttmp1.bmp"
!define SIDEPIC "${SRC}\assets\modern-wizard.bmp"
!define LICENSE_DE "${SRC}\xtras\copyright_de.txt"
!define LICENSE_EN "${SRC}\xtras\copyright_en.txt"

# Installer attributes
Name "${PRODUCTNAME} ${VERSION}"
OutFile "${SRC}\dist\${FILENAME}"
InstallDir "$PROGRAMFILES\${COMPANY}\${PRODUCTNAME} ${VERSION}"
SetCompressor /SOLID zlib # this allows to extract the installer files with 7zip etc.
CRCCheck on
XPStyle on
ShowInstDetails hide
ShowUninstDetails hide
InstallDirRegKey HKLM "${REGKEY}" Path
BrandingText /TRIMLEFT "${COMPANY}"
RequestExecutionLevel admin

# MultiUser
!define MULTIUSER_EXECUTIONLEVEL Admin
!define MULTIUSER_MUI
!define MULTIUSER_INSTALLMODE_DEFAULT_REGISTRY_KEY "${REGKEY}"
!define MULTIUSER_INSTALLMODE_DEFAULT_REGISTRY_VALUENAME MultiUserInstallMode
!define MULTIUSER_INSTALLMODE_COMMANDLINE
!define MULTIUSER_INSTALLMODE_INSTDIR "${COMPANY}\${PRODUCTNAME} ${VERSION}"
!define MULTIUSER_INSTALLMODE_INSTDIR_REGISTRY_KEY "${REGKEY}"
!define MULTIUSER_INSTALLMODE_INSTDIR_REGISTRY_VALUE "Path"

# MUI
!define MUI_ABORTWARNING
!define MUI_CUSTOMFUNCTION_GUIINIT "CustomGUIInit"
!define MUI_LANGDLL_REGISTRY_ROOT HKLM
!define MUI_LANGDLL_REGISTRY_KEY "${REGKEY}"
!define MUI_LANGDLL_REGISTRY_VALUENAME "InstallerLanguage"

# Included files
!include MUI2.nsh
!include MultiUser.nsh
!include Sections.nsh

# Variables
Var SMGroup

# Installer pages

# welcome page
!define MUI_WELCOMEPAGE_TITLE_3LINES
!define MUI_WELCOMEFINISHPAGE_BITMAP "${SIDEPIC}"
!insertmacro MUI_PAGE_WELCOME

# license page
!define MUI_LICENSEPAGE_CHECKBOX
!insertmacro MUI_PAGE_LICENSE $(MUILicense)

# directory selection page
!define MUI_DIRECTORYPAGE_VERIFYONLEAVE
!define MUI_PAGE_CUSTOMFUNCTION_LEAVE dirLeave
!insertmacro MUI_PAGE_DIRECTORY

# component selection page
!define MUI_COMPONENTSPAGE_SMALLDESC
!insertmacro MUI_PAGE_COMPONENTS

# startmenu page
!define MUI_STARTMENUPAGE_REGISTRY_ROOT HKLM
!define MUI_STARTMENUPAGE_REGISTRY_KEY "${REGKEY}"
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME StartMenuGroup
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "${COMPANY}\${PRODUCTNAME} ${VERSION}"
!insertmacro MUI_PAGE_STARTMENU "Application" $SMGroup

# installation progress page
!insertmacro MUI_PAGE_INSTFILES

# installer finish-page
!define MUI_FINISHPAGE_TITLE_3LINES
!define MUI_FINISHPAGE_TEXT_LARGE
!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_FINISHPAGE_RUN "$INSTDIR\wop.exe"
!define MUI_FINISHPAGE_RUN_NOTCHECKED
!define MUI_FINISHPAGE_SHOWREADME "$INSTDIR\XTRAS\readme.html"
!define MUI_FINISHPAGE_SHOWREADME_NOTCHECKED
!define MUI_FINISHPAGE_LINK "${PRODUCTNAME} Website"
!define MUI_FINISHPAGE_LINK_LOCATION "${URL}"
!define MUI_FINISHPAGE_NOREBOOTSUPPORT
!insertmacro MUI_PAGE_FINISH

# uninstaller finish-page
!define MUI_UNFINISHPAGE_NOAUTOCLOSE
!insertmacro MUI_UNPAGE_CONFIRM

# uninstaller progress page
!insertmacro MUI_UNPAGE_INSTFILES


# Installer languages & language strings
!insertmacro MUI_RESERVEFILE_LANGDLL
!insertmacro MUI_LANGUAGE English
!insertmacro MUI_LANGUAGE German

LicenseLangString MUILicense ${LANG_ENGLISH} ${LICENSE_EN}
LicenseLangString MUILicense ${LANG_GERMAN} ${LICENSE_DE}

LangString DESC_uninst ${LANG_ENGLISH} "Padman and his friends packed their stuff and are$\ngone from your harddrive now with worried hearts...$\n...looking forward hopefully to meet you again soon!$\n$\nSee ya!"
LangString DESC_uninst ${LANG_GERMAN} "Padman und seine Freunde haben ihre Sachen gepackt$\nund schweren Herzens Deine Festplatte verlassen...$\n...in der Hoffnung, Dich bald wieder zu sehen!$\n$\nBis dann!"

LangString ERR_dircheck1 ${LANG_ENGLISH} "This is not a valid installation path!"
LangString ERR_dircheck1 ${LANG_GERMAN} "Dies ist ein ungültiger Installationspfad!"

LangString ERR_dircheck2 ${LANG_ENGLISH} "Not enough free space!"
LangString ERR_dircheck2 ${LANG_GERMAN} "Nicht genügend freier Speicherplatz!"

LangString ERR_dircheck3 ${LANG_ENGLISH} "The destination folder already exists!$\nAre you sure you want to install into that directory?"
LangString ERR_dircheck3 ${LANG_GERMAN} "Das Installationsverzeichnis existiert bereits!$\nMöchtest Du trotzdem in dieses Verzeichnis installieren?"

LangString NAME_Section1 ${LANG_ENGLISH} "Main WoP-files"
LangString NAME_Section1 ${LANG_GERMAN} "WoP-Programmateien"

LangString DESC_Section1 ${LANG_ENGLISH} "All files needed to play WoP"
LangString DESC_Section1 ${LANG_GERMAN} "Alle benötigten Dateien um WoP zu spielen"

LangString NAME_Section2 ${LANG_ENGLISH} "Additional engines"
LangString NAME_Section2 ${LANG_GERMAN} "Zusätzliche Engines"

LangString DESC_Section2 ${LANG_ENGLISH} "The engines for Linux and Mac operating systems"
LangString DESC_Section2 ${LANG_GERMAN} "Die Engines für Linux- und Mac-Betriebssysteme"

LangString NAME_Section3 ${LANG_ENGLISH} "Mapping Resources"
LangString NAME_Section3 ${LANG_GERMAN} "Mapping-Ressourcen"

LangString DESC_Section3 ${LANG_ENGLISH} "Everything you need to create your own WoP-Maps"
LangString DESC_Section3 ${LANG_GERMAN} "Alles Notwendige um eigene WoP-Maps zu erstellen"

LangString NAME_Section4 ${LANG_ENGLISH} "Source code"
LangString NAME_Section4 ${LANG_GERMAN} "Quellcode"

LangString DESC_Section4 ${LANG_ENGLISH} "The source code of the game"
LangString DESC_Section4 ${LANG_GERMAN} "Der Quellcode des Spiels"

LangString NAME_Section5 ${LANG_ENGLISH} "Extra shortcuts"
LangString NAME_Section5 ${LANG_GERMAN} "Zusätzliche Verknüpfungen"

LangString DESC_Section5 ${LANG_ENGLISH} "Places shortcuts on the desktop and in the quicklaunch menu"
LangString DESC_Section5 ${LANG_GERMAN} "Erstellt Verknüpfungen auf dem Desktop und in der Schnellstart-Leiste"


# version info (windows: file properties -> details)
VIAddVersionKey /LANG=${LANG_GERMAN} ProductName "${PRODUCTNAME}"
VIAddVersionKey /LANG=${LANG_GERMAN} ProductVersion "${VERSION}"
VIAddVersionKey /LANG=${LANG_GERMAN} CompanyName "${COMPANY}"
VIAddVersionKey /LANG=${LANG_GERMAN} CompanyWebsite "${URL}"
VIAddVersionKey /LANG=${LANG_GERMAN} FileVersion "${VERSION}"
VIAddVersionKey /LANG=${LANG_GERMAN} FileDescription "${SHORTNAME} ${VERSION} Installer"
VIAddVersionKey /LANG=${LANG_GERMAN} LegalCopyright "${COMPANY}"
VIAddVersionKey /LANG=${LANG_GERMAN} OriginalFilename "${FILENAME}"

VIAddVersionKey /LANG=${LANG_ENGLISH} ProductName "${PRODUCTNAME}"
VIAddVersionKey /LANG=${LANG_ENGLISH} ProductVersion "${VERSION}"
VIAddVersionKey /LANG=${LANG_ENGLISH} CompanyName "${COMPANY}"
VIAddVersionKey /LANG=${LANG_ENGLISH} CompanyWebsite "${URL}"
VIAddVersionKey /LANG=${LANG_ENGLISH} FileVersion "${VERSION}"
VIAddVersionKey /LANG=${LANG_ENGLISH} FileDescription "${SHORTNAME} ${VERSION} Installer"
VIAddVersionKey /LANG=${LANG_ENGLISH} LegalCopyright "${COMPANY}"
VIAddVersionKey /LANG=${LANG_ENGLISH} OriginalFilename "${FILENAME}"


# Installer sections

# main files
Section $(NAME_Section1) Section1
    SectionIn RO
    SetOverwrite on

    SetOutPath "$INSTDIR\wop"
    File /r "${SRC}\wopfiles\*"
    SetOutPath "$INSTDIR\XTRAS"
    File /r "${SRC}\xtras\*"
    SetOutPath $INSTDIR
    File "${SRC}\engines\windows\libogg.dll"
    File "${SRC}\engines\windows\libtheora.dll"
    File "${SRC}\engines\windows\libvorbis.dll"
    File "${SRC}\engines\windows\libvorbisfile.dll"
    File "${SRC}\engines\windows\renderer_opengl1_x86.dll"
    File "${SRC}\engines\windows\SDL.dll"
    File "${SRC}\engines\windows\wop.exe"
    File "${SRC}\engines\windows\wopded.exe"

    !insertmacro MUI_STARTMENU_WRITE_BEGIN "Application"
        SetOutPath "$SMPROGRAMS\$SMGroup"
        File "${SRC}\xtras\World of Padman Website.url"
        File "${SRC}\xtras\World of Padman Archive.url"
          # game & uninstaller shortcuts
        CreateShortCut "$SMPROGRAMS\$SMGroup\Play ${PRODUCTNAME}.lnk" "$INSTDIR\wop.exe" "" "$INSTDIR\XTRAS\WoP.ico" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\${PRODUCTNAME} (safe-mode).lnk" "$INSTDIR\wop.exe" "+set r_fullscreen 1 +set r_mode 6 +set s_initsound 0" "$INSTDIR\wop.exe" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\${PRODUCTNAME} (safe-mode windowed).lnk" "$INSTDIR\wop.exe" "+set r_fullscreen 0 +set r_mode 6 +set s_initsound 0" "$INSTDIR\wop.exe" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\$(UninstallLink).lnk" "$INSTDIR\UnWoP.exe" "" "$INSTDIR\XTRAS\UnWoP.ico" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\${PRODUCTNAME} ReadMe.lnk" "$INSTDIR\XTRAS\readme.html" "" "$INSTDIR\XTRAS\WoP.ico" 0
        # server shortcuts
        CreateDirectory "$SMPROGRAMS\$SMGroup\Dedicated Server Shortcuts"
        CreateShortCut "$SMPROGRAMS\$SMGroup\Dedicated Server Shortcuts\Spray Your Color - dedicated Server.lnk" "$INSTDIR\wopded.exe" "+set dedicated 1 +exec server-sprayyourcolour.cfg" "$INSTDIR\XTRAS\WoP.ico" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\Dedicated Server Shortcuts\Big Ballon - dedicated Server.lnk" "$INSTDIR\wopded.exe" "+set dedicated 1 +exec server-bigballoon.cfg" "$INSTDIR\XTRAS\WoP.ico" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\Dedicated Server Shortcuts\Last Pad Standing - dedicated Server.lnk" "$INSTDIR\wopded.exe" "+set dedicated 1 +exec server-lastpadstanding.cfg" "$INSTDIR\XTRAS\WoP.ico" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\Dedicated Server Shortcuts\Capture The Lolly - dedicated Server.lnk" "$INSTDIR\wopded.exe" "+set dedicated 1 +exec server-capturethelolly.cfg" "$INSTDIR\XTRAS\WoP.ico" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\Dedicated Server Shortcuts\All Gametypes - dedicated Server.lnk" "$INSTDIR\wopded.exe" "+set dedicated 1 +exec server-allgametypes.cfg" "$INSTDIR\XTRAS\WoP.ico" 0
        CreateDirectory "$SMPROGRAMS\$SMGroup\Listen-Server Shortcuts"
        CreateShortCut "$SMPROGRAMS\$SMGroup\Listen-Server Shortcuts\Spray Your Color - listen-Server.lnk" "$INSTDIR\wop.exe" "+exec server-sprayyourcolour.cfg" "$INSTDIR\XTRAS\WoP.ico" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\Listen-Server Shortcuts\Big Ballon - listen-Server.lnk" "$INSTDIR\wop.exe" "+exec server-bigballoon.cfg" "$INSTDIR\XTRAS\WoP.ico" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\Listen-Server Shortcuts\Last Pad Standing - listen-Server.lnk" "$INSTDIR\wop.exe" "+exec server-lastpadstanding.cfg" "$INSTDIR\XTRAS\WoP.ico" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\Listen-Server Shortcuts\Capture The Lolly - listen-Server.lnk" "$INSTDIR\wop.exe" "+exec server-capturethelolly.cfg" "$INSTDIR\XTRAS\WoP.ico" 0
        CreateShortCut "$SMPROGRAMS\$SMGroup\Listen-Server Shortcuts\All Gametypes - listen-Server.lnk" "$INSTDIR\wop.exe" "+exec server-allgametypes.cfg" "$INSTDIR\XTRAS\WoP.ico" 0
    !insertmacro MUI_STARTMENU_WRITE_END

    WriteRegStr HKLM "${REGKEY}\Components" Main 1
SectionEnd


# engines
Section /o $(NAME_Section2) Section2
    SetOverwrite on
    SetOutPath "$INSTDIR\wop.app"
    File /r "${SRC}\engines\mac\wop.app\*"
    SetOutPath $INSTDIR
    File "${SRC}\engines\linux\renderer_opengl1_i386.so"
    File "${SRC}\engines\linux\renderer_opengl1_x86_64.so"
    File "${SRC}\engines\linux\wop.i386"
    File "${SRC}\engines\linux\wop.x86_64"
    File "${SRC}\engines\linux\wopded.i386"
    File "${SRC}\engines\linux\wopded.x86_64"
    WriteRegStr HKLM "${REGKEY}\Components" Engines 1
SectionEnd


# mappingtools
Section /o $(NAME_Section3) Section3
    SetOverwrite on
    SetOutPath "$INSTDIR\XTRAS\editing files"
    File /r "${SRC}\editing\*"
    WriteRegStr HKLM "${REGKEY}\Components" Mapping 1
SectionEnd


# source code
Section /o $(NAME_Section4) Section4
    SetOverwrite on
    SetOutPath "$INSTDIR\XTRAS\editing files"
    File "${SRC}\source\worldofpadman-1.6_svn2178.zip"
    WriteRegStr HKLM "${REGKEY}\Components" Source 1
SectionEnd


# extra shortcuts
Section /o $(NAME_Section5) Section5
    CreateShortCut "$DESKTOP\Play ${PRODUCTNAME}.lnk" "$INSTDIR\wop.exe" "" "$INSTDIR\wop.exe" 0
    CreateShortCut "$QUICKLAUNCH\Play ${PRODUCTNAME}.lnk" "$INSTDIR\wop.exe" "" "$INSTDIR\wop.exe" 0
    WriteRegStr HKLM "${REGKEY}\Components" Shortcuts 1
SectionEnd


; Section descriptions
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${Section1} $(DESC_Section1)
    !insertmacro MUI_DESCRIPTION_TEXT ${Section2} $(DESC_Section2)
    !insertmacro MUI_DESCRIPTION_TEXT ${Section3} $(DESC_Section3)
    !insertmacro MUI_DESCRIPTION_TEXT ${Section4} $(DESC_Section4)
    !insertmacro MUI_DESCRIPTION_TEXT ${Section5} $(DESC_Section5)
!insertmacro MUI_FUNCTION_DESCRIPTION_END


Section -post SEC0001
    SetOutPath $INSTDIR
    # write application- and uninstaller-registry-keys
    WriteRegStr HKLM "${REGKEY}" Path $INSTDIR
    WriteUninstaller "$INSTDIR\UnWoP.exe"
    WriteRegStr HKLM "${UNREGKEY}" DisplayName "${PRODUCTNAME} ${VERSION}"
    WriteRegStr HKLM "${UNREGKEY}" DisplayVersion "${VERSION}"
    WriteRegStr HKLM "${UNREGKEY}" Publisher "${COMPANY}"
    WriteRegStr HKLM "${UNREGKEY}" URLInfoAbout "${URL}"
    WriteRegStr HKLM "${UNREGKEY}" DisplayIcon "$INSTDIR\UnWoP.exe"
    WriteRegStr HKLM "${UNREGKEY}" UninstallString "$INSTDIR\UnWoP.exe"
    WriteRegDWORD HKLM "${UNREGKEY}" NoModify 1
    WriteRegDWORD HKLM "${UNREGKEY}" NoRepair 1
SectionEnd


# Macro for selecting uninstaller sections
!macro SELECT_UNSECTION SECTION_NAME UNSECTION_ID
    Push $R0
    ReadRegStr $R0 HKLM "${REGKEY}\Components" "${SECTION_NAME}"
    StrCmp $R0 1 0 next${UNSECTION_ID}
    !insertmacro SelectSection "${UNSECTION_ID}"
    GoTo done${UNSECTION_ID}
    next${UNSECTION_ID}:
        !insertmacro UnselectSection "${UNSECTION_ID}"
    done${UNSECTION_ID}:
        Pop $R0
!macroend


# Uninstaller sections

# delete files
Section /o -un.Main UNSEC0000
    RmDir /r /REBOOTOK "$INSTDIR\XTRAS"
    RmDir /r /REBOOTOK "$INSTDIR\wop"
    Delete /REBOOTOK "$INSTDIR\wop.exe"
    Delete /REBOOTOK "$INSTDIR\wopded.exe"
    Delete /REBOOTOK "$INSTDIR\libogg.dll"
    Delete /REBOOTOK "$INSTDIR\libtheora.dll"
    Delete /REBOOTOK "$INSTDIR\libvorbis.dll"
    Delete /REBOOTOK "$INSTDIR\libvorbisfile.dll"
    Delete /REBOOTOK "$INSTDIR\renderer_opengl1_x86.dll"
    Delete /REBOOTOK "$INSTDIR\SDL.dll"
    # linux
    Delete /REBOOTOK "$INSTDIR\wop.i386"
    Delete /REBOOTOK "$INSTDIR\wopded.i386"
    Delete /REBOOTOK "$INSTDIR\wop.x86_64"
    Delete /REBOOTOK "$INSTDIR\wopded.x86_64"
    Delete /REBOOTOK "$INSTDIR\renderer_opengl1_i386.so"
    Delete /REBOOTOK "$INSTDIR\renderer_opengl1_x86_64.so"
    # mac
    RmDir /r /REBOOTOK "$INSTDIR\wop.app"
    # files created by wop
    Delete /REBOOTOK "$INSTDIR\botlib.log"
    Delete /REBOOTOK "$INSTDIR\stderr.txt"
    Delete /REBOOTOK "$INSTDIR\wopkey"
SectionEnd

# delete firewall-rules, registry-keys and shortcuts
Section -un.post UNSEC0001
    DeleteRegKey HKLM "${REGKEY}"
    DeleteRegKey HKLM "${UNREGKEY}"

    Delete /REBOOTOK "$DESKTOP\Play ${PRODUCTNAME}.lnk"
    Delete /REBOOTOK "$QUICKLAUNCH\Play ${PRODUCTNAME}.lnk"
    RmDir /r /REBOOTOK "$SMPROGRAMS\$SMGroup"
    Delete /REBOOTOK "$INSTDIR\UnWoP.exe"
    RmDir /REBOOTOK $INSTDIR
    Push $R0
    StrCpy $R0 $SMGroup 1
    StrCmp $R0 ">" no_smgroup
    no_smgroup:
        Pop $R0
SectionEnd


# Installer functions

# splash-screen, language-select
Function .onInit
    InitPluginsDir
    Push $R1
    File "/oname=$PLUGINSDIR\spltmp.bmp" "${SPLPIC}"
    advsplash::show 1500 1000 1000 -1 "$PLUGINSDIR\spltmp" # no .bmp extension here!
    Pop $R1
    Pop $R1
    !insertmacro MUI_LANGDLL_DISPLAY
    !insertmacro MULTIUSER_INIT
FunctionEnd

# background-image
Function CustomGUIInit
    Push $R1
    Push $R2
    BgImage::SetReturn /NOUNLOAD on
    BgImage::SetBg /NOUNLOAD /GRADIENT 0 0 160 0 0 0
    Pop $R1
    Strcmp $R1 success 0 error
    System::call "user32::GetSystemMetrics(i 0)i.R1"
    System::call "user32::GetSystemMetrics(i 1)i.R2"
    IntOp $R1 $R1 - 1024
    IntOp $R1 $R1 / 2
    IntOp $R2 $R2 - 768
    IntOp $R2 $R2 / 2
    File "/oname=$PLUGINSDIR\insttmp1.bmp" "${BGPIC}"
    BGImage::AddImage /NOUNLOAD "$PLUGINSDIR\insttmp1.bmp" $R1 $R2
    CreateFont $R1 "Verdana" 26 700 /ITALIC
    BGImage::AddText /NOUNLOAD $(^SetupCaption) $R1 255 255 255 16 8 500 100
    Pop $R1
    Strcmp $R1 success 0 error
    BGImage::Redraw /NOUNLOAD
    Goto done
    error:
        MessageBox MB_OK|MB_ICONSTOP $R1
    done:
        Pop $R2
        Pop $R1
FunctionEnd


# dircheck
Function dirLeave
  GetInstDirError $0
  ${Switch} $0
    ${Case} 0
      ${Break}
    ${Case} 1
      MessageBox MB_OK $(ERR_dircheck1) #invalid directory
      Abort
      ${Break}
    ${Case} 2
      MessageBox MB_OK $(ERR_dircheck2) #not enough space
      Abort
      ${Break}
  ${EndSwitch}
  IfFileExists "$INSTDIR\*.*" Exists NonExists
  Exists:
    MessageBox MB_YESNO|MB_ICONEXCLAMATION|MB_DEFBUTTON2 $(ERR_dircheck3) IDYES +2 #dir already exists
    Abort
  NonExists:
FunctionEnd

# bgimage-kill
Function .onGUIEnd
    BGImage::Destroy
FunctionEnd


# Uninstaller functions

Function un.onInit
    !insertmacro MUI_STARTMENU_GETFOLDER "Application" $SMGroup
    !insertmacro MUI_UNGETLANGUAGE
    !insertmacro MULTIUSER_UNINIT
    !insertmacro SELECT_UNSECTION Main ${UNSEC0000}
FunctionEnd

# uninstall farewell
Function un.onUninstSuccess
    HideWindow
    MessageBox MB_OK|MB_ICONINFORMATION $(DESC_uninst)
FunctionEnd
