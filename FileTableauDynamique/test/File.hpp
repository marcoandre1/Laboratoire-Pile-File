/**
 * \file File.hpp
 * \brief Classe définissant le type abstrait file
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \author Abder
 * \version 0.3
 * \date Septembre 2013
 *
 * Representation d'une file (LIFO - Last In First Out) dans un tableau dynamique
 *
 */

#include "ContratException.h"

/**
 * \namespace lab04
 * \brief Namespace du laboratoire 4.
 */
namespace lab04 {
/**
 * \brief Constructeur
 * \pre Il faut qu'il y ait suffisamment de mémoire
 * \post Une instance de la classe File est initialisàe
 * \exception bad_alloc si la mémoire est insuffisante
 */
template<typename T>
File<T>::File(const int max) :
		m_tete(0), m_queue(0), m_tailleMax(max), m_cardinalite(0) 
{
	m_tab = new T[m_tailleMax];
}

/**
 *  \brief Destructeur.
 *  \post L'instance de File est détruite.
 */
template<typename T>
File<T>::~File() 
{
	delete[] m_tab;
}

/**
 *  \brief Constructeur de copie.
 *
 * \pre Il faut qu'il y ait suffisamment de mémoire
 * \post La file passée en paramètre est copiée
 * \param[in] p_source La file à copier
 * \exception bad_alloc s'il n'y a pas assez de mémoire
 */
template<typename T>
File<T>::File(const File& p_source) :
		m_tete(p_source.m_tete), m_queue(p_source.m_queue), m_tailleMax(
				p_source.m_tailleMax), m_cardinalite(p_source.m_cardinalite) 
{
	m_tab = new T[m_tailleMax];
	for (int i = 0; i < m_cardinalite; ++i) 
	{
		m_tab[i] = p_source.m_tab[i];
	}
}

/**
 * \brief Surcharge de l'opérateur =
 *
 * \pre Il y a assez de mémoire pour l'opération
 * \post La file passée en paramètre est copiée
 * \param[in] p_source La file à copier
 * \exception bad_alloc si la précondition n'est pas respectée
 */
template<typename T>
const File<T>& File<T>::operator =(const File<T>& p_source) 
{
	if (this != &p_source) 
	{
		if (m_tab != NULL) 
		{
			delete[] m_tab;
		}

		m_tete = p_source.m_tete;
		m_queue = p_source.m_queue;
		m_cardinalite = p_source.m_cardinalite;
		m_tailleMax = p_source.m_tailleMax;
		m_tab = new T[m_tailleMax];
		for (int i = 0; i < m_cardinalite; ++i) 
		{
			m_tab[i] = p_source.m_tab[i];
		}
	}
	return *this;
}

/**
 * \brief Enfiler un nouvel élément dans la file
 * \pre La file n'est pas pleine
 * \post La file comprend un élément de plus
 * \param[in] p_element L'élément à enfiler.
 *
 */
template<typename T>
void File<T>::enfiler(const T & p_element) 
{
	PRECONDITION(m_cardinalite < m_tailleMax);

	m_tab[m_queue] = p_element;
	m_queue = (m_queue + 1) % m_tailleMax;
	m_cardinalite++;
	POSTCONDITION(m_tab[(m_queue - 1) % m_tailleMax] == p_element);
	INVARIANTS();
}

/*
 * \brief Défiler un élément
 * \pre La file ne doit pas être vide
 * \post La file comprend un élément de moins
 * \return L'élément au début de la file
 *
 */
template<typename T>
T File<T>::defiler() 
{
	PRECONDITION(!estVide());

	T elementaDefiler = m_tab[m_tete];
	m_tete = (m_tete + 1) % m_tailleMax;
	m_cardinalite--;

	return elementaDefiler;
}

/**
 * \brief Retourne la cardinalité de la file
 *
 * \post La file est inchangée
 * \return La cardinalité de la pile est retournée
 */
template<typename T>
int File<T>::taille() const 
{
	return m_cardinalite;
}

/**
 * \brief Vérifier si la file est vide
 *
 * \post La file est inchangée
 * \return Bool indiquant si la file est vide ou non
 */
template<typename T>
bool File<T>::estVide() const 
{
	return m_cardinalite == 0;
}

/**
 * \brief Vérifier si la file est pleine
 *
 * \post La file est inchangée
 * \return Bool indiquant si la file est pleine ou non
 */
template<typename T>
bool File<T>::estPleine() const 
{
	return m_cardinalite == m_tailleMax;
}

/**
 * \brief Retourner le premier élément de la file
 * \pre La file ne doit pas être vide
 * \post La file est inchangée
 * \post Le premier élément de la file est retourné
 * \return Une référence constante sur le premier élément de la file
 *
 */
template<typename T>
const T& File<T>::premier() const 
{
	PRECONDITION(!estVide());
	return m_tab[m_tete];
}

/**
 * \brief Retourner le dernier élément de la file
 * \pre La file ne doit pas être vide
 * \post La file est inchangée
 * \post Le dernier élément de la file est retourné
 * \return Une référence constante sur le dernier élément de la file
 *
 */
template<typename T>
const T & File<T>::dernier() const 
{
	PRECONDITION(!estVide());
	return m_tab[m_queue - 1];
}

/**
 * \brief Surcharger l'opérateur [].
 *
 * La position 0 correspond au début de la file.
 *
 * \pre L'indice doit être compris entre 0 et la cardinalité de la file - 1.
 * \param[in] p_position La position de recherche
 * \post L'élément à la position voulue est retournée.
 * \post La file est inchangée.
 */
template<typename T>
T File<T>::operator [](const int & p_position) const 
{
	PRECONDITION(p_position >= 0 and p_position <= m_cardinalite - 1);
	return m_tab[p_position];
}

/**
 * \brief Affiche la file
 * \param[in, out] p_out Le flux de sortie
 * \param[in] p_source Une file
 * \post La pile est inchangée
 * \return Une référence sur le flux de sortie
 */
template<typename U>
std::ostream& operator <<(std::ostream& p_out, const File<U>& p_source) 
{
	p_out << "[";
	for (int i = 0; i < p_source.taille(); ++i) {
		p_out << p_source[i] << ",";
	}
	p_out << "]";
	return p_out;
}

/**
 * \brief Vérifier les invariant de la classe
 * \post La classe est inchangée.
 */
template<typename T>
void File<T>::verifieInvariant() const 
{
	INVARIANT(m_cardinalite <= m_tailleMax);
	INVARIANT(m_tailleMax >= 0);
	INVARIANT(m_cardinalite >= 0);
}

} //Fin du namespace

