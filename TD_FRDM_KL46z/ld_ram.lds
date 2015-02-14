MEMORY
	{
        flash_config(rx): ORIGIN = 0x00000400, LENGTH = 32
	flash(rx): ORIGIN = 2K, LENGTH = 254K
	RAML(!rx): ORIGIN = 0x1FFFE000, LENGTH = 8K
	RAMH(!rx): ORIGIN = 0x20000000, LENGTH = 24K		
	}
_stack = ORIGIN(RAML) + LENGTH(RAMH);

SECTIONS
{

	.flash_config : {
	  *(.flash_config)
	} > flash_config
	.text : {
	*(.text)
	}>RAMH
	.rodata : {
	*(.rodata)
	}>RAMH
	.data : {
	*(.data)
	}>RAMH
	.bss : {
	_bstart = .;
	*(.bss)*(COMMON);
	}>RAMH
	_bend = .;
}
ENTRY(_start)

