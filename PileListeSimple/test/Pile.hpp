#include "ContratException.h"

namespace lab04 {

// À compléter ...

template<typename T>
std::ostream & operator <<(std::ostream & p_out, const Pile<T> & p_source) 
{
	typename Pile<T>::Noeud * tmp = p_source.m_sommet;
	p_out << "Pile: [";
	while (tmp != NULL) 
	{
		p_out << tmp->m_el;
		if (tmp->m_suivant != nullptr)
			p_out << ",";
		tmp = tmp->m_suivant;
	}
	p_out << "]";
	return p_out;
}

// Méthodes privées
// ------------------------- (2) --------------------
// --------------------------------------------------
template<typename T>
void Pile<T>::empiler

// ------------------------- (3) --------------------
// --------------------------------------------------
template<typename T>
T Pile<T>::depiler()
{
    PRECONDITION(!estVide());

    elem sentinelle = m_sommet;
    m_sommet = m_sommet->m_suivant;
    int cardinaliteCourante = m_cardinalite;
    T valeur = sentinelle->m_el;
}

template<typename T>
const Pile<T> & Pile<T>::operator =(const Pile<T> & p_source) {

}

// ------------------------- (5) --------------------
// --------------------------------------------------
template<typename T>
Pile<T>::Pile(const Pile & p_source) : m_source
{
    PRECONDITION(!estVide());

    elem sentinelle = m_sommet;
    m_sommet = m_sommet->m_suivant;
    int cardinaliteCourante = m_cardinalite;
    T valeur = sentinelle->m_el;
}

// ------------------------- (6) --------------------
// --------------------------------------------------
template<typename T>
Pile<T>::Pile(const Pile & p_source) : m_source
{
    PRECONDITION(!estVide());

    elem sentinelle = m_sommet;
    m_sommet = m_sommet->m_suivant;
    int cardinaliteCourante = m_cardinalite;
    T valeur = sentinelle->m_el;
}

} //Fin du namespace
