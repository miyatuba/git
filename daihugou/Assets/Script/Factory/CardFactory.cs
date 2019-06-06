using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CardFactory : MonoBehaviour
{
    public GameObject spade1;
    public GameObject spade2;
    public GameObject spade3;
    public GameObject spade4;
    public GameObject spade5;
    public GameObject spade6;
    public GameObject spade7;
    public GameObject spade8;
    public GameObject spade9;
    public GameObject spade10;
    public GameObject spade11;
    public GameObject spade12;
    public GameObject spade13;
    public GameObject heart1;
    public GameObject heart2;
    public GameObject heart3;
    public GameObject heart4;
    public GameObject heart5;
    public GameObject heart6;
    public GameObject heart7;
    public GameObject heart8;
    public GameObject heart9;
    public GameObject heart10;
    public GameObject heart11;
    public GameObject heart12;
    public GameObject heart13;
    public GameObject dia1;
    public GameObject dia2;
    public GameObject dia3;
    public GameObject dia4;
    public GameObject dia5;
    public GameObject dia6;
    public GameObject dia7;
    public GameObject dia8;
    public GameObject dia9;
    public GameObject dia10;
    public GameObject dia11;
    public GameObject dia12;
    public GameObject dia13;
    public GameObject club1;
    public GameObject club2;
    public GameObject club3;
    public GameObject club4;
    public GameObject club5;
    public GameObject club6;
    public GameObject club7;
    public GameObject club8;
    public GameObject club9;
    public GameObject club10;
    public GameObject club11;
    public GameObject club12;
    public GameObject club13;
    public GameObject joker1;
    public GameObject joker2;

    // mark_idは1:スペード、2:ハート、3:ダイア、4:クラブ、5:joker
    Hashtable[] card_data_list;
    
    // Start is called before the first frame update
    void Start()
    {
        this.card_data_list = new Hashtable[] {
            new Hashtable{ ["card_id"] = 1,  ["value"] = 1,  ["mark_id"] = 1 , ["card_object"] = this.spade1, },
            new Hashtable{ ["card_id"] = 2,  ["value"] = 2,  ["mark_id"] = 1 , ["card_object"] = this.spade2, },
            new Hashtable{ ["card_id"] = 3,  ["value"] = 3,  ["mark_id"] = 1 , ["card_object"] = this.spade3, },
            new Hashtable{ ["card_id"] = 4,  ["value"] = 4,  ["mark_id"] = 1 , ["card_object"] = this.spade4, },
            new Hashtable{ ["card_id"] = 5,  ["value"] = 5,  ["mark_id"] = 1 , ["card_object"] = this.spade5, },
            new Hashtable{ ["card_id"] = 6,  ["value"] = 6,  ["mark_id"] = 1 , ["card_object"] = this.spade6, },
            new Hashtable{ ["card_id"] = 7,  ["value"] = 7,  ["mark_id"] = 1 , ["card_object"] = this.spade7, },
            new Hashtable{ ["card_id"] = 8,  ["value"] = 8,  ["mark_id"] = 1 , ["card_object"] = this.spade8, },
            new Hashtable{ ["card_id"] = 9,  ["value"] = 9,  ["mark_id"] = 1 , ["card_object"] = this.spade9, },
            new Hashtable{ ["card_id"] = 10, ["value"] = 10, ["mark_id"] = 1 , ["card_image"] = this.spade10,},
            new Hashtable{ ["card_id"] = 11, ["value"] = 11, ["mark_id"] = 1 , ["card_image"] = this.spade11,},
            new Hashtable{ ["card_id"] = 12, ["value"] = 12, ["mark_id"] = 1 , ["card_image"] = this.spade12,},
            new Hashtable{ ["card_id"] = 13, ["value"] = 13, ["mark_id"] = 1 , ["card_image"] = this.spade13,},
            new Hashtable{ ["card_id"] = 14, ["value"] = 1,  ["mark_id"] = 2 , ["card_image"] = this.heart1, },
            new Hashtable{ ["card_id"] = 15, ["value"] = 2,  ["mark_id"] = 2 , ["card_image"] = this.heart2, },
            new Hashtable{ ["card_id"] = 16, ["value"] = 3,  ["mark_id"] = 2 , ["card_image"] = this.heart3, },
            new Hashtable{ ["card_id"] = 17, ["value"] = 4,  ["mark_id"] = 2 , ["card_image"] = this.heart4, },
            new Hashtable{ ["card_id"] = 18, ["value"] = 5,  ["mark_id"] = 2 , ["card_image"] = this.heart5, },
            new Hashtable{ ["card_id"] = 19, ["value"] = 6,  ["mark_id"] = 2 , ["card_image"] = this.heart6, },
            new Hashtable{ ["card_id"] = 20, ["value"] = 7,  ["mark_id"] = 2 , ["card_image"] = this.heart7, },
            new Hashtable{ ["card_id"] = 21, ["value"] = 8,  ["mark_id"] = 2 , ["card_image"] = this.heart8, },
            new Hashtable{ ["card_id"] = 22, ["value"] = 9,  ["mark_id"] = 2 , ["card_image"] = this.heart9, },
            new Hashtable{ ["card_id"] = 23, ["value"] = 10, ["mark_id"] = 2 , ["card_image"] = this.heart10,},
            new Hashtable{ ["card_id"] = 24, ["value"] = 11, ["mark_id"] = 2 , ["card_image"] = this.heart11,},
            new Hashtable{ ["card_id"] = 25, ["value"] = 12, ["mark_id"] = 2 , ["card_image"] = this.heart12,},
            new Hashtable{ ["card_id"] = 26, ["value"] = 13, ["mark_id"] = 2 , ["card_image"] = this.heart13,},
            new Hashtable{ ["card_id"] = 27, ["value"] = 1,  ["mark_id"] = 3 , ["card_image"] = this.dia1, },
            new Hashtable{ ["card_id"] = 28, ["value"] = 2,  ["mark_id"] = 3 , ["card_image"] = this.dia2, },
            new Hashtable{ ["card_id"] = 29, ["value"] = 3,  ["mark_id"] = 3 , ["card_image"] = this.dia3, },
            new Hashtable{ ["card_id"] = 30, ["value"] = 4,  ["mark_id"] = 3 , ["card_image"] = this.dia4, },
            new Hashtable{ ["card_id"] = 31, ["value"] = 5,  ["mark_id"] = 3 , ["card_image"] = this.dia5, },
            new Hashtable{ ["card_id"] = 32, ["value"] = 6,  ["mark_id"] = 3 , ["card_image"] = this.dia6, },
            new Hashtable{ ["card_id"] = 33, ["value"] = 7,  ["mark_id"] = 3 , ["card_image"] = this.dia7, },
            new Hashtable{ ["card_id"] = 34, ["value"] = 8,  ["mark_id"] = 3 , ["card_image"] = this.dia8, },
            new Hashtable{ ["card_id"] = 35, ["value"] = 9,  ["mark_id"] = 3 , ["card_image"] = this.dia9, },
            new Hashtable{ ["card_id"] = 36, ["value"] = 10, ["mark_id"] = 3 , ["card_image"] = this.dia10,},
            new Hashtable{ ["card_id"] = 37, ["value"] = 11, ["mark_id"] = 3 , ["card_image"] = this.dia11,},
            new Hashtable{ ["card_id"] = 38, ["value"] = 12, ["mark_id"] = 3 , ["card_image"] = this.dia12,},
            new Hashtable{ ["card_id"] = 39, ["value"] = 13, ["mark_id"] = 3 , ["card_image"] = this.dia13,},
            new Hashtable{ ["card_id"] = 40, ["value"] = 1,  ["mark_id"] = 4 , ["card_image"] = this.club1, },
            new Hashtable{ ["card_id"] = 41, ["value"] = 2,  ["mark_id"] = 4 , ["card_image"] = this.club2, },
            new Hashtable{ ["card_id"] = 42, ["value"] = 3,  ["mark_id"] = 4 , ["card_image"] = this.club3, },
            new Hashtable{ ["card_id"] = 43, ["value"] = 4,  ["mark_id"] = 4 , ["card_image"] = this.club4, },
            new Hashtable{ ["card_id"] = 44, ["value"] = 5,  ["mark_id"] = 4 , ["card_image"] = this.club5, },
            new Hashtable{ ["card_id"] = 45, ["value"] = 6,  ["mark_id"] = 4 , ["card_image"] = this.club6, },
            new Hashtable{ ["card_id"] = 46, ["value"] = 7,  ["mark_id"] = 4 , ["card_image"] = this.club7, },
            new Hashtable{ ["card_id"] = 47, ["value"] = 8,  ["mark_id"] = 4 , ["card_image"] = this.club8, },
            new Hashtable{ ["card_id"] = 48, ["value"] = 9,  ["mark_id"] = 4 , ["card_image"] = this.club9, },
            new Hashtable{ ["card_id"] = 49, ["value"] = 10, ["mark_id"] = 4 , ["card_image"] = this.club10,},
            new Hashtable{ ["card_id"] = 50, ["value"] = 11, ["mark_id"] = 4 , ["card_image"] = this.club11,},
            new Hashtable{ ["card_id"] = 51, ["value"] = 12, ["mark_id"] = 4 , ["card_image"] = this.club12,},
            new Hashtable{ ["card_id"] = 52, ["value"] = 13, ["mark_id"] = 4 , ["card_image"] = this.club13,},
            new Hashtable{ ["card_id"] = 53, ["value"] = 0,  ["mark_id"] = 5 , ["card_image"] = this.joker1, },
            new Hashtable{ ["card_id"] = 54, ["value"] = 0,  ["mark_id"] = 5 , ["card_image"] = this.joker2, },
        };

    }

    // Update is called once per frame
    void Update()
    {

    }

    public CardCollection create()
    {
        Dictionary<int, CardModel> card_list = new Dictionary<int, CardModel>();
        foreach (Hashtable card_data in card_data_list)
        {
            CardModel card = new CardModel(card_data);
            int card_id = card.GetCardId();
            card_list.Add(card_id, card);
        }
        

        CardCollection cards = new CardCollection(card_list);
        return cards;
    }
}
