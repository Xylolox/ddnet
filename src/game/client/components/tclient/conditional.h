#ifndef GAME_CLIENT_COMPONENTS_SOLLY_CONDITIONAL_H
#define GAME_CLIENT_COMPONENTS_SOLLY_CONDITIONAL_H

#include <engine/console.h>
#include <game/client/component.h>

#include <functional>
#include <string>
#include <vector>

class CConditional : public CComponent
{
private:
	// TODO use maps
	std::vector<std::pair<std::string, std::function<int(char *pOut, int Length)>>> m_vVariables;
	std::vector<std::pair<std::string, std::function<int(const char *pParam, char *pOut, int Length)>>> m_vFunctions;
	int ParseValue(char *pBuf, int Length);

public:
	const IConsole::IResult *m_pResult = nullptr;

	void ParseString(char *pBuf, int Length);
	static void ConIfeq(IConsole::IResult *pResult, void *pUserData);
	static void ConIfneq(IConsole::IResult *pResult, void *pUserData);
	static void ConIfreq(IConsole::IResult *pResult, void *pUserData);
	static void ConIfrneq(IConsole::IResult *pResult, void *pUserData);
	static void ConReturn(IConsole::IResult *pResult, void *pUserData);
	void OnConsoleInit() override;
	int Sizeof() const override { return sizeof(*this); }
};

#endif
