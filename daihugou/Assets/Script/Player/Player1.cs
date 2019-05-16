using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player1 : MonoBehaviour
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

    public void DrawCards()
    {
        List<CardModel> card_list = this.cards.GetCardList();

        float x_base_position = -1;
        int draw_order = 0;
        foreach (CardModel card in card_list)
        {
            GameObject card_image = card.GetCardImage();
            card_image.transform.position = new Vector3(x_base_position, -3, 0);
            x_base_position += 0.2f;
            card_image.GetComponent<SpriteRenderer>().sortingOrder = draw_order;
            draw_order += 1;
            card_image.SetActive(true);
        }

    }
}