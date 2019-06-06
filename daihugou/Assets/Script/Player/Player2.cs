using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player2 : MonoBehaviour
{
    private CardCollection cards = new CardCollection(new Dictionary<int, CardModel>());

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

    private void DrawCards()
    {
        Dictionary<int, CardModel> card_list = this.cards.GetCardList();

        float y_base_position = 1;
        int draw_order = 0;
        Debug.Log(card_list.Count);
        foreach (KeyValuePair<int, CardModel> card_pair in card_list)
        {
            GameObject card_object = card_pair.Value.GetCardObject();
            card_object.transform.position = new Vector3(8, y_base_position, 0);
            card_object.transform.rotation = Quaternion.Euler(0f, 0f, 90f);
            y_base_position -= 0.2f;
            card_object.GetComponent<SpriteRenderer>().sortingOrder = draw_order;
            draw_order += 1;
            card_object.SetActive(true);
        }
    }
}
