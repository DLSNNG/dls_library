<?php

  function test_form($form, &$form_state, $values) {
    
    $field1 = isset($values['field1']) ? $values['field1'] : '';
    $field2 = isset($values['field2']) ? $values['field2'] : '';
    $target = isset($values['target']) ? $values['target'] : '';
    
    $form = array(
      '#type' => 'state_form',
      '#params_map' => array(
        'test1' => 'field1',
        'test2' => 'field2',
      ),
      '#target_url' => $target,
      '#pre_render' => array('state_form_prerender'),
      '#submit' => array('state_form_save_state'),
      'field1' => array(
        '#type' => 'regex_textfield',
        '#title' => 'Test Field',
        '#regex_message' => 'Accession Number should be 2 Upper Case letters followed by 8 numbers',
        '#regex' => '/[A-Z]{2}[0-9]{8}$/',
        '#default_value' => $field1,
      ),
      'field2' => array(
        '#type' => 'regex_textfield',
        '#regex' => '/[0-9]{1,2}\/[0-9]{1,2}\/[0-9]{4}$/',
        '#regex_message' => 'Date must follow the format MM/DD/YYYY.',
        '#title' => 'Date',
        '#default_value' => $field2,
      ),
      'actions' => array(
        '#type' => 'action',
        'submit' => array(
          '#type' => 'submit',
          '#value' => 'Save',
        ),
      ),
    );
    return $form;
  }