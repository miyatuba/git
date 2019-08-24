using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HeroineSelect : MonoBehaviour
{
    private int selectHeroineId;

    public GameObject input_object;

    public GameObject vampire_hiroine_object;
    public GameObject succubus_hiroine_object;
    public GameObject seiren_hiroine_object;

    public GameObject vampire_hiroine_mask_object;
    public GameObject succubus_hiroine_mask_object;
    public GameObject seiren_hiroine_mask_object;

    List<GameObject> hiroine_list = new List<GameObject>();
    List<GameObject> hiroine_mask_list = new List<GameObject>();

    void Start()
    {
        //初期の選択状態
        selectHeroineId = HeroineTypeId.VAMPIRE_HEROINE_ID;
        this.succubus_hiroine_mask_object.SetActive(true);
        this.seiren_hiroine_mask_object.SetActive(true);

        this.hiroine_list.Add(this.vampire_hiroine_object);
        this.hiroine_list.Add(this.succubus_hiroine_object);
        this.hiroine_list.Add(this.seiren_hiroine_object);

        this.hiroine_mask_list.Add(this.vampire_hiroine_mask_object);
        this.hiroine_mask_list.Add(this.succubus_hiroine_mask_object);
        this.hiroine_mask_list.Add(this.seiren_hiroine_mask_object);

        this.vampire_hiroine_object.GetComponent<Heroine>().setId(HeroineTypeId.VAMPIRE_HEROINE_ID);
        this.succubus_hiroine_object.GetComponent<Heroine>().setId(HeroineTypeId.SUCCUBUS_HEROINE_ID);
        this.seiren_hiroine_object.GetComponent<Heroine>().setId(HeroineTypeId.SEIREN_HEROINE_ID);

        this.vampire_hiroine_mask_object.GetComponent<HeroineMask>().setId(HeroineTypeId.VAMPIRE_HEROINE_ID);
        this.succubus_hiroine_mask_object.GetComponent<HeroineMask>().setId(HeroineTypeId.SUCCUBUS_HEROINE_ID);
        this.seiren_hiroine_mask_object.GetComponent<HeroineMask>().setId(HeroineTypeId.SEIREN_HEROINE_ID);

    }

    void Update()
    {
        GameObject clicked_game_object = null;

        if (Input.GetMouseButtonDown(0)) {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit2D hit2d = Physics2D.Raycast((Vector2)ray.origin, (Vector2)ray.direction);

            if (hit2d)
            {
                clicked_game_object = hit2d.transform.gameObject;
            }

        }

        if (clicked_game_object != null)
        {
            clicked_game_object.SetActive(true);
            foreach (GameObject hiroine_mask in this.hiroine_mask_list)
            {
                string clicked_object_name = clicked_game_object.name;
                if (clicked_object_name == hiroine_mask.name) {
                    hiroine_mask.SetActive(false);
                    this.selectHeroineId = hiroine_mask.GetComponent<HeroineMask>().getId();
                }
                else {
                    hiroine_mask.SetActive(true);
                }
            }

            //進むとか戻るとかの処理
        }

    }


}
