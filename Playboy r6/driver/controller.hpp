#pragma once

#include "driver/driver.hpp"
#include "func/function.hpp"

namespace controller
{
	bool setup ()
	{
		function.setup ();

		if (!driver.is_mapped ()) NULL; // map driver here

		while (!driver.get_pid ()) {
			driver.set_pid (_ ("UnityWndClass").c_str (), _ ("Rust").c_str ());
			std::this_thread::sleep_for (std::chrono::milliseconds (1));
		}

		return driver.is_mapped () && driver.get_pid ();
	}
}