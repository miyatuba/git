using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CardShuffleService : MonoBehaviour
{
    public GameObject player1;
    public GameObject player2;
    public GameObject player3;
    public GameObject player4;

    public GameObject card_factory;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void Execute()
    {
        //カード生成
        CardCollection cards = card_factory.GetComponent<CardFactory>().create();

        //各プレイヤーに配る
        while (true)
        {
            if (cards.IsEmpty()) break;
            CardModel card1 = cards.RandomPickUp();
            player1.GetComponent<Player1>().addCard(card1);

            if (cards.IsEmpty()) break;
            CardModel card2 = cards.RandomPickUp();
            player2.GetComponent<Player2>().addCard(card2);

            if (cards.IsEmpty()) break;
            CardModel card3 = cards.RandomPickUp();
            player3.GetComponent<Player3>().addCard(card3);

            if (cards.IsEmpty()) break;
            CardModel card4 = cards.RandomPickUp();
            player4.GetComponent<Player4>().addCard(card4);

        }

    }
}
