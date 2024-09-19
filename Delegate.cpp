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
	void Delegate<params...>::operator+=(std::function<void(params...)> callback)
	{
		Subscribe(callback);
	}

	template<class ...params>
	void Delegate<params...>::operator-=(std::function<void(params...)> callback)
	{
		Unsubscribe(callback);
	}
	template<class ...params>
	void Delegate<params...>::Subscribe(std::function<void(params...)> callback)
	{
		callbacks.push_back(callback);

	}

	template<class ...params>
	void Delegate<params...>::Unsubscribe(std::function<void(params...)> callback)
	{
		for (int i = 0; i < callbacks.size(); ++i) {
			if (callbacks[i] == callback) {
				callbacks.erase(i);
			}
		}
	}

}