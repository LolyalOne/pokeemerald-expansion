#ifndef POKEEMERALD_MUGSHOTS_H
#define POKEEMERALD_MUGSHOTS_H

const u32 gMugshotPic_Leticia[] = INCGFX_U32("graphics/mugshots/leticia.png", ".4bpp.lz");
const u32 gMugshotPic_Livia[] = INCGFX_U32("graphics/mugshots/livia.png", ".4bpp.lz");
const u32 gMugshotPic_AnaBeatriz[] = INCGFX_U32("graphics/mugshots/ana_beatriz.png", ".4bpp.lz");
const u32 gMugshotPic_Daniel[] = INCGFX_U32("graphics/mugshots/daniel.png", ".4bpp.lz");
const u32 gMugshotPic_Matheus[] = INCGFX_U32("graphics/mugshots/matheus.png", ".4bpp.lz");
const u32 gMugshotPic_MariaClara[] = INCGFX_U32("graphics/mugshots/maria_clara.png", ".4bpp.lz");

const u16 gMugshotPal_Leticia[] = INCGFX_U16("graphics/mugshots/palettes/leticia.pal", ".gbapal");
const u16 gMugshotPal_Livia[] = INCGFX_U16("graphics/mugshots/palettes/livia.pal", ".gbapal");
const u16 gMugshotPal_AnaBeatriz[] = INCGFX_U16("graphics/mugshots/palettes/ana_beatriz.pal", ".gbapal");
const u16 gMugshotPal_Daniel[] = INCGFX_U16("graphics/mugshots/palettes/daniel.pal", ".gbapal");
const u16 gMugshotPal_Matheus[] = INCGFX_U16("graphics/mugshots/palettes/matheus.pal", ".gbapal");
const u16 gMugshotPal_MariaClara[] = INCGFX_U16("graphics/mugshots/palettes/maria_clara.pal", ".gbapal");

static const struct CompressedSpriteSheet sMugshotSpriteSheets[] = {
    {gMugshotPic_Leticia, 0x800, 10000},
    {gMugshotPic_Livia, 0x800, 10001},
    {gMugshotPic_AnaBeatriz, 0x800, 10002},
    {gMugshotPic_Daniel, 0x800, 10003},
    {gMugshotPic_Matheus, 0x800, 10004},
    {gMugshotPic_MariaClara, 0x800, 10005},
};

static const struct SpritePalette sMugshotPalettes[] = {
    {gMugshotPal_Leticia, 10000},
    {gMugshotPal_Livia, 10001},
    {gMugshotPal_AnaBeatriz, 10002},
    {gMugshotPal_Daniel, 10003},
    {gMugshotPal_Matheus, 10004},
    {gMugshotPal_MariaClara, 10005},
};

static const struct OamData sOamData_Mugshot =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_Mugshot[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Mugshot[] =
{
    sSpriteAnim_Mugshot,
};

static const struct SpriteTemplate sSpriteTemplate_Mugshot =
{
    .tileTag = 10000,
    .paletteTag = 10000,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

#endif
