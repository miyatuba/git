using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CardCollection : MonoBehaviour
{
    private Dictionary<int, CardModel> card_list;
    private List<int> card_id_list;

    public CardCollection(Dictionary<int, CardModel> card_list)
    {
        this.card_list = card_list;
        List<int> card_id_list = new List<int>();
        foreach (KeyValuePair<int, CardModel> card_pair in this.card_list)
        {
            int card_id = card_pair.Value.GetCardId();
            card_id_list.Add(card_id);
        }
        this.card_id_list = card_id_list;
    }
    
    public bool IsEmpty()
    {
        return this.card_list.Count == 0;
    }

    public void Push(CardModel card)
    {
        int card_id = card.GetCardId();
        this.card_list.Add(card_id, card);
        this.card_id_list.Add(card_id);
    }

    public CardModel RandomPickUp()
    {
        int index = UnityEngine.Random.Range(0, card_id_list.Count);
        int card_id = this.card_id_list[index];
        CardModel target_card = this.card_list[card_id];
        this.card_id_list.RemoveAt(index);
        this.RemoveCardList(target_card);
        return target_card;
    }

    private void RemoveCardList(CardModel target_card)
    {
        int card_id = target_card.GetCardId();
        this.card_list.Remove(card_id);
    }


    public Dictionary<int, CardModel> GetCardList()
    {
        return this.card_list;
    }
}
