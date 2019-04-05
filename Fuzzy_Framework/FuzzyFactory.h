#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "ExpressionFactory.h"

#include "UnaryShadowExpression.h"
#include "BinaryShadowExpression.h"
#include "NaryShadowExpression.h"

#include "And.h"
#include "Or.h"
#include "Then.h"
#include "Agg.h"
#include "Not.h"
#include "Is.h"

#include "SugenoConclusion.h"
#include "SugenoDefuzz.h"
#include "MamdaniDefuzz.h"


namespace fuzzy {
	template<class T>
	class FuzzyFactory : public core::ExpressionFactory<T>
	{
	private:
		core::UnaryShadowExpression<T> * not;

		core::BinaryShadowExpression<T> * and;
		core::BinaryShadowExpression<T> * or;
		core::BinaryShadowExpression<T> * then;
		core::BinaryShadowExpression<T> * defuzz;
		core::BinaryShadowExpression<T> * agg;
		

		core::NaryShadowExpression<T>* conclusion;
		core::NaryShadowExpression<T>* sugeno;
	public:
		FuzzyFactory() {};
		
		FuzzyFactory(Not<T>* _not, And<T>* _and, Or<T>* _or, Then<T>* _then, Agg<T>* _agg, MamdaniDefuzz<T>* _m);   // factory pour le model Mamdani
		FuzzyFactory(Not<T>* _not, And<T>* _and, Or<T>* _or, Then<T>* _then, Agg<T>* _agg, SugenoConclusion<T>* _sugC, SugenoDefuzz<T>* _sugD);   //pour le model Sugeno
		virtual ~FuzzyFactory() {};

		//Reste plus qu'à definir les methodes
		
		core::Expression<T>* newAnd(core::Expression<T>*, core::Expression<T>*);
		core::Expression<T>* newOr(core::Expression<T>*, core::Expression<T>*);
		core::Expression<T>* newThen(core::Expression<T>*, core::Expression<T>*);
		core::Expression<T>* newAgg(core::Expression<T>*, core::Expression<T>*);
		core::Expression<T>* newDefuzz(core::Expression<T>*, core::Expression<T>*);
		core::Expression<T>* newNot(core::Expression<T>*);
		core::Expression<T>* newIs(Is<T>* ,core::Expression<T>*);

		void changeAnd(And<T>*);
		void changeOr(Or<T>*);
		void changeThen(Then<T>*);
		void changeAgg(Agg<T>*);
		void changeNot(Not<T>*);
		void changeIs(Is<T>*);
		void changeDefuzz(MamdaniDefuzz<T>*);
		void changeSugeno(SugenoDefuzz<T>*);
		void changeConclusion(SugenoConclusion<T>*);

	};

}

#endif // !FUZZYFACTORY_H
