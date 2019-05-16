using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CardCollection : MonoBehaviour
{
    List<CardModel> card_list;

    public CardCollection(List<CardModel> card_list)
    {
        this.card_list = card_list;
    }
    
    public bool IsEmpty()
    {
        return this.card_list.Count == 0;
    }

    public void Push(CardModel card)
    {
        this.card_list.Add(card);
    }

    public CardModel RandomPickUp()
    {
        CardModel target_card = this.GetRamdom();
        this.card_list.Remove(target_card);
        return target_card;
    }

    private CardModel GetRamdom()
    {
        return this.card_list[Random.Range(0, this.card_list.Count)];
    }

    public List<CardModel> GetCardList()
    {
        return this.card_list;
    }
}
