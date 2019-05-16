using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player2 : MonoBehaviour
{
    private CardCollection cards = new CardCollection(new List<CardModel>());

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //毎回描画するのも美しくないので後程改善
        this.DrawCards();
    }

    public void addCard(CardModel card)
    {
        this.cards.Push(card);
    }

    private DrawCards()
    {

    }
}
