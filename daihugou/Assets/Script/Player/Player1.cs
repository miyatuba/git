using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player1 : MonoBehaviour
{
    private CardCollection cards = new CardCollection(new Dictionary<int, CardModel>());

    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        this.CheckCollision();

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

        float x_base_position = -1;
        int draw_order = 0;
        foreach (KeyValuePair<int, CardModel> card_pair in card_list)
        {
            GameObject card_object = card_pair.Value.GetCardObject();
            card_object.transform.position = new Vector3(x_base_position, -3, 0);
            x_base_position += 0.2f;
            card_object.GetComponent<SpriteRenderer>().sortingOrder = draw_order;
            draw_order += 1;
            card_object.SetActive(true);
            card_object.GetComponent<Collider2D>().isTrigger = true;
        }

    }

    private void CheckCollision()
    {
        // 左クリックを取得
        if (Input.GetMouseButtonDown(0))
        {
            // クリックしたスクリーン座標をrayに変換
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            // Rayの当たったオブジェクトの情報を格納する
            RaycastHit hit = new RaycastHit();
            // オブジェクトにrayが当たった時
            if (Physics.Raycast(ray, out hit, 100f))
            {
                // rayが当たったオブジェクトの名前を取得
                string objectName = hit.collider.gameObject.name;
                Debug.Log(objectName);
            }
        }
    }

}