// ----------------------- (2) -------------------------
// -----------------------------------------------------
TEST_F(PileTest, ajoutUnElementOk) {
    pile1.empiler(c4);
    EXPECT_FALSE(pile1.estVide());
    EXPECT_EQ(1, pile1.taille());
}

TEST_F(PileTest, ajoutUnElementEnleverUnElements) {
    pile1.empiler(c1);
    EXPECT_EQ(c1, pile1.depiler());
    EXPECT_TRUE(pile1.estVide());
}

// ----------------------- (3) -------------------------
// -----------------------------------------------------
// T Pile<T>::depiler()
TEST_F(PileTest, depilerPileVideLanceLogicError) {
    Pile<int> pileVide;
    EXPECT_THROW(pileVide.depiler(), PreconditionException
}

// ----------------------- (4) -------------------------
// -----------------------------------------------------
// Pile<T>::Pile(const Pile & p_source)
// const Pile<T> & Pile<T>::operator =(const Pile<T>

// ----------------------- (5) -------------------------
// -----------------------------------------------------
// const T& Pile<T>::top() const
TEST_F(PileTest, ajoutTroisElementOk) {
    pile1.empiler(c1);
    EXPECT_EQ(c1, pile1.top());
    EXPECT_EQ(1, pile1.taille());
    pile1.empiler(c2);
    EXPECT_EQ(c2, pile1.top());
   
}