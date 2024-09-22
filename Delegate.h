#pragma once
#include <vector>
#include <functional>
namespace Events {

	template<class... params>
	class Delegate {

	public:
		void Invoke(params...args)
		{
			for (unsigned int i = 0; i < callbacks.size(); ++i) {
				callbacks[i](args...);
			}
		}
		void operator+=(std::function<void(params...)> callback) 
		{
			Subscribe(callback);
		}
		void operator()(params...args)
		{
			Invoke(args...);
		}
		void operator-=(std::function<void(params...)> callback)
		{
			Unsubscribe(callback);
		}
		void Subscribe(std::function<void(params...)> callback)
		{
			callbacks.push_back(callback);

		}
		void Unsubscribe(std::function<void(params...)> callback)
		{
			for (int i = 0; i < callbacks.size(); ++i) {
				if (callbacks[i] == callback) {
					callbacks.erase(i);
				}
			}
		}

	private:
		std::vector<std::function<void(params...)>> callbacks;
	};
}