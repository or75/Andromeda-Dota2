#pragma once

template<typename T>
class Singleton
{
public:
	static auto Instance()->T*
	{
		static T* m_pInstance = nullptr;

		if ( m_pInstance == nullptr )
			m_pInstance = new T();

		return m_pInstance;
	}
};
