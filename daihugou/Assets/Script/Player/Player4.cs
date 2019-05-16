using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player4 : MonoBehaviour
{
    private CardCollection cards = new CardCollection(new List<CardModel>());

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void addCard(CardModel card)
    {
        this.cards.Push(card);
    }

}
