#pragma once
#include <vector>
#include <functional>
#include <utility>

namespace Events {

	template<class... params>
	class Delegate {

	public:
		using CallbackId = int;

		void Invoke(params...args)
		{
			for (unsigned int i = 0; i < callbacks.size(); ++i) {
				callbacks[i].second(args...);
			}
		}
		void operator()(params...args)
		{
			Invoke(args...);
		}

		CallbackId operator+=(std::function<void(params...)> callback)
		{
			return Subscribe(callback);
		}

		void operator-=(std::function<void(params...)> callback)
		{
			Unsubscribe(callback);
		}
		CallbackId Subscribe(std::function<void(params...)> callback)
		{
			callbacks.emplace_back(++nextId, std::move(callback));
			return nextId;

		}
		void Unsubscribe(CallbackId id)
		{
			callbacks.erase(
				std::remove_if(callbacks.begin(), callbacks.end(),
					[id](const std::pair<CallbackId, std::function<void(params...)>>& p) {
						return p.first == id;
					}),
				callbacks.end()
			);
		}

	private:
		std::vector<std::pair<CallbackId, std::function<void(params...)>>> callbacks;
		CallbackId nextId = 0;

	};
}