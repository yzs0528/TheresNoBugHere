@echo off
set UnrealEditorPath=E:\UnrealEngin\UE_5.5\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe
%UnrealEditorPath% -ProjectFiles -project=%~dp0TheresNoBugHere.uproject -game -progress -engine
pause