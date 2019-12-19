// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

// fwdecl unittest classes
namespace TerminalAppLocalTests
{
    class CommandlineTest;
};
namespace TerminalApp
{
    class Commandline;
};

class TerminalApp::Commandline
{
public:
    ~Commandline();

    static constexpr std::wstring_view Delimiter{ L";" };
    static constexpr std::wstring_view EscapedDelimiter{ L"\\;" };

    size_t Argc() const;
    char** Argv() const;
    const std::vector<std::wstring>& Wargs() const;
    char** BuildArgv();
    void AddArg(const std::wstring& nextArg);

private:
    std::vector<std::wstring> _wargs;
    char** _argv = nullptr;
    void _resetArgv();

    friend class TerminalAppLocalTests::CommandlineTest;
};