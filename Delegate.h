#pragma once
#include <vector>
#include <functional>
namespace Events {

	template<class... params>
	class Delegate {

	public:
		void Invoke(params...args);

		void operator+=(std::vector<std::function<void(params...)>> callback);
		void operator-=(std::vector<std::function<void(params...)>> callback);

	private:
		std::vector<std::function<void(params...)>> callbacks;
	};
}