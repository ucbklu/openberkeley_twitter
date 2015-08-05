<?php
$plugin = array(
  'title' => t('Twitter Embed Code'),
  'description' => t('Displays a Twitter embedded object.'),
  'single' => TRUE,
  'content_types' => array('openberkeley_twitter_embed'),
  'render callback' => 'openberkeley_twitter_embed_content_type_render',
  //'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'openberkeley_twitter_embed_content_type_edit_form',
  'category' => t('Embeddable content'),
);

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function openberkeley_twitter_embed_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['openberkeley_twitter_embed_label'] = array(
    '#type' => 'textarea',
    '#title' => t('Twitter Embed Code'),
    '#description' => t('Paste your Twitter embed code here.'),
    '#default_value' => !empty($conf['openberkeley_twitter_embed_label']) ? $conf['openberkeley_twitter_embed_label'] : '',
  );
  return $form;
}

/**
 * Form validation callback for openberkeley_twitter_embed_content_type_edit_form().
 */
function openberkeley_widgets_openberkeley_twitter_embed_content_type_edit_form_validate($form, &$form_state) {
/*
  $subtype = $form_state['subtype_name'];
  $widgets = openberkeley_widgets_simple_embed_widgets();
  $widget = $widgets[$subtype];

  if (!call_user_func($widget['extract link callback'], $form_state['values']['link'], $widget)) {
    form_set_error('link', t('Invalid Google Forms link or embed code.'));
  }

  $height = $form_state['values']['height'];
  if (!is_numeric($height) || intval($height) != $height || intval($height) < 0) {
    form_set_error('height', t('Height must be a positive, whole number.'));
  }
*/
  return TRUE;
}
/**
 * Ctools edit form submit handler.
 *
 * @param $form
 * @param $form_state
 */
function openberkeley_twitter_embed_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('openberkeley_twitter_embed_label') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Render callback for the openberkeley_twitter_embed content type.
 */
function openberkeley_widgets_openberkeley_simple_embed_content_type_render($subtype, $conf, $args, $context) {
//  $widgets = openberkeley_widgets_simple_embed_widgets();
//  $widget = $widgets[$subtype];

  // For security purposes, we re-validate the link before rendering.
  /*
  $conf['link'] = call_user_func($widget['extract link callback'], $conf['link'], $widget);
  if (empty($conf['link'])) {
    return;
  }

  // Generate the embed code.
  $embed = call_user_func($widget['embed callback'], $conf, $widget);
*/

  $pane = new stdClass();
  $pane->content = "This is a test";
  return $pane;
}