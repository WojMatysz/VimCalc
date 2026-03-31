#include "core/core.hpp"
#include "tui/tui.hpp"
#include "interface/coreUiControler.hpp"

int main(int argc, char * argv[])
{
	core::Core core;
	tui::Tui tui;
	interface::CoreUiControler coreTuiControler{&core, &tui};
	tui.run();
	return 0;
};
