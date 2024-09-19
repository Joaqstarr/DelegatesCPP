#include "Delegate.h"
namespace Events {

	template<class ...params>
	inline void Delegate<params...>::Invoke(params...args)
	{
		for (int i = 0; i < callbacks.size(); ++i) {
			callbacks[i](args);
		}
	}


	template<class ...params>
	void Delegate<params...>::operator+=(std::vector<std::function<void(params...)>> callback)
	{
		callbacks.push_back(callback);
	}

	template<class ...params>
	void Delegate<params...>::operator-=(std::vector<std::function<void(params...)>> callback)
	{
		for (int i = 0; i < callbacks.size(); ++i) {
			if (callbacks[i] == callback) {
				callbacks.erase(i);
			}
		}
	}

}