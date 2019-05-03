#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "MamdaniDefuzz.h"

namespace fuzzy
{
	template <class T>
	class CogDefuzz: public MamdaniDefuzz<T>
	{
	public:
		CogDefuzz() {};
		virtual ~CogDefuzz() {};

	protected:
		virtual T Defuzz(const Shape&) const;
	};

	template <class T>
	T CogDefuzz<T>::Defuzz(const Shape& s) const
	{
		std::vector<T> product;
		std::vector<T>::const_iterator iteratorX = s.first.begin();
		std::vector<T>::const_iterator iteratorY = s.second.begin();
		
		for (; iteratorY != s.second.end(); ++iteratorY, ++iteratorX)
			product.push_back(*iteratorX * *iteratorY);

		T sumProduct = 0;
		T sumY = 0;

		// (somme des xi*yi) / (somme des yi)
		return std::accumulate(product.begin(), product.end(), sumProduct) / std::accumulate(s.second.begin(), s.second.end(), sumY);
	}
}

#endif  //!COGDEFUZZ_H