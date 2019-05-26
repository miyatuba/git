using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player4 : MonoBehaviour
{
    private CardCollection cards = new CardCollection(new Dictionary<int, CardModel>());

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        this.DrawCards();
    }

    public void addCard(CardModel card)
    {
        this.cards.Push(card);
    }

    public void DrawCards()
    {
        Dictionary<int, CardModel> card_list = this.cards.GetCardList();

        float x_base_position = -1;
        int draw_order = 0;
        foreach (KeyValuePair<int, CardModel> card_pair in card_list)
        {
            GameObject card_image = card_pair.Value.GetCardImage();
            card_image.transform.position = new Vector3(x_base_position, 3, 0);
            x_base_position += 0.2f;
            card_image.GetComponent<SpriteRenderer>().sortingOrder = draw_order;
            draw_order += 1;
            card_image.SetActive(true);
        }

    }
}
