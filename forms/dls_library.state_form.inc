<?php

  function state_form() {
    $form = array(
      '#type' => 'state_form',
      '#target_url' => current_path(),
      '#pre_render' => array('state_form_prerender'),
      '#submit' => array('state_form_save_state'),
      '#params_map' => array(), // override in implementation
    );
    return $form;
  }