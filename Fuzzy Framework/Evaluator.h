#ifndef EVALUATOR_H
#define EVALUATOR_H

namespace fuzzy
{
	template <class T>
	class Evaluator
	{
	public:
		typedef std::pair<std::vector<T>, std::vector<T>> Shape;

		Shape BuildShape(const T&, const T&, const T&, core::ValueModel<T>*, core::Expression<T>*) const;
		std::ostream& PrintShape(const Shape&, std::ostream&) const;
	};

	template <class T>
	typename Evaluator<T>::Shape Evaluator<T>::BuildShape(const T& min, const T& max, const T& step, core::ValueModel<T>* value, core::Expression<T>* e) const
	{
		std::vector<T> x, y;
		T mem = value->evaluate();  // pour éviter les effets de bord

		for (T i = min; i <= max; i += step)
		{
			value->setValue(i);
			x.push_back(i);
			y.push_back(e->evaluate());
		}

		value->setValue(mem);  // pour éviter les effets de bord

		return Shape(x, y);   // instanciation de la forme à partir de x et y
	}

	template <class T>
	typename std::ostream& Evaluator<T>::PrintShape(const Shape& s, std::ostream& os) const
	{
		for (std::vector<T>::const_iterator iteratY = s.second.begin(); iteratY != s.second.end(); iteratY++)
		{
			unsigned compteur = (unsigned) ((*iteratY) * 10);

			while (compteur != 0)
			{
				os << "-";
				compteur--;
			}
			os << "*" << std::endl;
		}
		return os;
	}
}

#endif  //!EVALUATOR_H