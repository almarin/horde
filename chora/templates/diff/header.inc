<div class="horde-content">
 <form method="get" action="diff.php">
  <?php echo Chora::formInputs() ?>
  <input type="hidden" name="f" value="<?php echo htmlspecialchars(Horde_Util::getFormData('f')) ?>" />
  <input type="hidden" name="r1" value="<?php echo htmlspecialchars(Horde_Util::getFormData('r1')) ?>" />
  <input type="hidden" name="r2" value="<?php echo htmlspecialchars(Horde_Util::getFormData('r2')) ?>" />
  <?php echo _("Download diff as: ") ?>
  <select name="t" onchange="this.form.submit()">
   <option value="unified"><?php echo _("Unified") ?></option>
  </select>
  <input type="submit" value="<?php echo _("Get Diff") ?>" />
 </form>
</div>

<?php if (!empty($log_messages)): ?>
<div class="commitList">
<?php
$view = $injector->createInstance('Horde_View');
echo $view->renderPartial('app/views/logMessage', array('collection' => array_map(function ($a) { return $a->toHash(); }, $log_messages), 'locals' => array('diff_page' => 1)));
?>
</div>
<?php endif; ?>
