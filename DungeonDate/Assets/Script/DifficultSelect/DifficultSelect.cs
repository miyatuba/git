using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;
using UnityEngine.EventSystems;
using System;

public class DifficultSelect : MonoBehaviour
{
    private int selectDifficultId;

    public EventSystem event_system;

    public GameObject back_object;
    public GameObject decision_object;

    public GameObject easy_object;
    public GameObject nomal_object;
    public GameObject hard_object;

    public GameObject easy_not_select_object;
    public GameObject nomal_not_select_object;
    public GameObject hard_not_select_object;


    public GameObject help_button;
    public GameObject help_canvase;


    private const int EASY_DIFFICULT_TYPE_ID = 1;
    private const int NOMAL_DIFFICULT_TYPE_ID = 2;
    private const int HARD_DIFFICULT_TYPE_ID = 3;

    List<GameObject> difficult_not_select_list = new List<GameObject>();
    List<GameObject> difficult_select_list = new List<GameObject>();

    // Start is called before the first frame update
    void Start()
    {
        selectDifficultId = DifficultSelect.EASY_DIFFICULT_TYPE_ID;

        this.difficult_select_list.Add(this.easy_object);
        this.difficult_select_list.Add(this.nomal_object);
        this.difficult_select_list.Add(this.hard_object);

        this.difficult_not_select_list.Add(this.easy_not_select_object);
        this.difficult_not_select_list.Add(this.nomal_not_select_object);
        this.difficult_not_select_list.Add(this.hard_not_select_object);

        this.easy_object.GetComponent<Difficult>().setId(DifficultSelect.EASY_DIFFICULT_TYPE_ID);
        this.nomal_object.GetComponent<Difficult>().setId(DifficultSelect.NOMAL_DIFFICULT_TYPE_ID);
        this.hard_object.GetComponent<Difficult>().setId(DifficultSelect.HARD_DIFFICULT_TYPE_ID);

        this.easy_not_select_object.GetComponent<Difficult>().setId(DifficultSelect.EASY_DIFFICULT_TYPE_ID);
        this.nomal_not_select_object.GetComponent<Difficult>().setId(DifficultSelect.NOMAL_DIFFICULT_TYPE_ID);
        this.hard_not_select_object.GetComponent<Difficult>().setId(DifficultSelect.HARD_DIFFICULT_TYPE_ID);
    }

    // Update is called once per frame
    void Update()
    {
    
        if (Input.GetMouseButtonDown(0))
        {
            if (this.event_system.currentSelectedGameObject == null)
            {
                this.clickGameObject();
            }else {
                this.clickUI();
            }


           

        }


        
    }

    private void clickGameObject()
    {
        GameObject clicked_game_object = null;

        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        RaycastHit2D hit2d = Physics2D.Raycast((Vector2)ray.origin, (Vector2)ray.direction);

        if (hit2d)
        {
            clicked_game_object = hit2d.transform.gameObject;
        }

        if (clicked_game_object != null)
        {
            string clicked_object_name = clicked_game_object.name;
            foreach (GameObject difficult_not_select in this.difficult_not_select_list)
            {

                if (clicked_object_name == difficult_not_select.name)
                {
                    this.selectDifficultId = difficult_not_select.GetComponent<Difficult>().getId();
                    this.difficult_select_list[selectDifficultId - 1].SetActive(true);
                }
                else if (clicked_object_name == this.easy_not_select_object.name || 
                         clicked_object_name == this.nomal_not_select_object.name || 
                         clicked_object_name == this.hard_not_select_object.name)
                {
                    this.selectDifficultId = difficult_not_select.GetComponent<Difficult>().getId();
                    this.difficult_select_list[selectDifficultId - 1].SetActive(false);
                }
            }

            //help help_button上のループと分ける必要あり
            if (clicked_object_name == this.help_button.name)
            {
                this.help_canvase.SetActive(true);
            }

            //進むとか戻るとかの処理
        }
    }

    private void clickUI()
    {
        switch(this.event_system.currentSelectedGameObject.name)
        {
            case "help_canvas":
                this.help_canvase.SetActive(false);
                break;
        }
    }
}
