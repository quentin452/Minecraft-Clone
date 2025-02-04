#include "../Inventory.h"
#include "../../Application.h"
#include "../../SFML-2.5.0/include/SFML/Graphics.hpp"
//#include "../../../lib/SFML-2.5.0/x64/include/SFML/Graphics.hpp"
#include <../../GLEW_64/include/GL/glew.h>
#include <iostream>

Inventory::Inventory(Player &player, Application &app)
	: m_pPlayer{ &player },
	m_updateIcons{ true }
{
	m_slots[5].item.setData(BlockId::Snow, 64);
	m_slots[6].item.setData(BlockId::StoneAxe, 1);
	m_slots[8].item.setData(BlockId::Apple, 10);

	m_slots[7].item.setData(BlockId::Glowstone, 64);

	m_inventoryGUITexture.loadFromFile("Res/Textures/Interface/inventoryGUI.png");
	m_inventoryGUI.setTexture(&m_inventoryGUITexture);
	m_craftingTableGUITexture.loadFromFile("Res/Textures/Interface/craftingTableGUI.png");
	m_craftingTableGUI.setTexture(&m_craftingTableGUITexture);
	m_toolbarTexture.loadFromFile("Res/Textures/Interface/toolbar.png");
	m_toolbar.setTexture(&m_toolbarTexture);
	m_heldItemFrameTexture.loadFromFile("Res/Textures/Interface/toolbarHeldItem.png");
	m_heldItemFrame.setTexture(&m_heldItemFrameTexture);
	m_itemTextBackgroundTexture.loadFromFile("Res/Textures/Interface/textBackground.png");
	m_itemTextBackground.setTexture(&m_itemTextBackgroundTexture);

	m_font.loadFromFile("Res/Fonts/MinecraftRegular.otf");

	setInterfacePositions(app);

	setSlotsPositions();

	setTextSettings(app);

	m_grabbedItemDrawer.setSizes(m_invSlotSize);

	setToolDurabilityBarSettings();

	m_highlightSlotSquare.setFillColor(sf::Color(255, 255, 255, 127));
	m_highlightSlotSquare.setOrigin(0.0f, m_invSlotSize);
	m_highlightSlotSquare.setSize({ m_invSlotSize * 1.05f, m_invSlotSize * 1.05f });
}

void Inventory::setInterfacePositions(const Application &app)
{
	float inventoryWidth = app.getWindow().getSize().x / 3.6f;
	float aspectRatio = (float)m_inventoryGUITexture.getSize().y / (float)m_inventoryGUITexture.getSize().x;
	// inventory height = 165,75px, width = 176,75px
	m_invPixelSize = inventoryWidth / 176.0f;
	m_invSlotSize = m_invPixelSize * 16;
	m_invDistanceBetweenSlots = m_invPixelSize * 18;

	m_inventoryGUI.setSize({ inventoryWidth, inventoryWidth * aspectRatio });
	m_inventoryGUI.setOrigin(
		m_inventoryGUI.getGlobalBounds().width / 2,
		m_inventoryGUI.getGlobalBounds().height / 2);
	m_inventoryGUI.setPosition(
		app.getWindow().getSize().x / 2,
		app.getWindow().getSize().y / 2);

	m_craftingTableGUI.setSize(m_inventoryGUI.getSize());
	m_craftingTableGUI.setOrigin(m_inventoryGUI.getOrigin());
	m_craftingTableGUI.setPosition(m_inventoryGUI.getPosition());

	aspectRatio = (float)m_toolbarTexture.getSize().y / (float)m_toolbarTexture.getSize().x;
	m_toolbar.setSize({ inventoryWidth, inventoryWidth * aspectRatio });
	m_toolbar.setOrigin(
		m_toolbar.getGlobalBounds().width / 2,
		m_toolbar.getGlobalBounds().height);
	m_toolbar.setPosition(
		app.getWindow().getSize().x / 2,
		app.getWindow().getSize().y);

	aspectRatio = (float)m_heldItemFrameTexture.getSize().y / (float)m_heldItemFrameTexture.getSize().x;
	m_toolbarSlotSize = m_invSlotSize;
	m_toolbarDistanceBetweenSlots = inventoryWidth / 9;
	m_heldItemFrame.setSize({
		m_toolbarSlotSize * 1.4f,
		m_toolbarSlotSize * 1.4f * aspectRatio });
	m_heldItemFrame.setOrigin(
		m_heldItemFrame.getLocalBounds().width * 0.136f,
		m_heldItemFrame.getGlobalBounds().height);
	m_heldItemFrame.setPosition(
		m_toolbar.getGlobalBounds().left + m_toolbarDistanceBetweenSlots * 0.073f,
		app.getWindow().getSize().y);
}

void Inventory::setSlotsPositions()
{
	//m_grabbedSlot.slotId = SlotId::Grabbed;

	int invStartPosX = m_inventoryGUI.getGlobalBounds().left;
	int invStartPosY = m_inventoryGUI.getGlobalBounds().top + m_inventoryGUI.getGlobalBounds().height;
	setInventorySlotsPositions({ invStartPosX, invStartPosY });

	int toolStartPosX = m_toolbar.getGlobalBounds().left;
	int toolStartPosY = m_toolbar.getGlobalBounds().top + m_toolbar.getGlobalBounds().height;
	setToolbarSlotsPositions({ toolStartPosX, toolStartPosY });

	int armorStartPosX = m_inventoryGUI.getGlobalBounds().left + 8 * m_invPixelSize;
	int armorStartPosY = m_inventoryGUI.getGlobalBounds().top + 8 * m_invPixelSize + m_invSlotSize;
	setArmorSlotsPositions({ armorStartPosX, armorStartPosY });

	int craftStartPosX = m_inventoryGUI.getGlobalBounds().left
		+ m_inventoryGUI.getGlobalBounds().width / 2.0f;
	int craftStartPosY = m_inventoryGUI.getGlobalBounds().top
		+ 7.5f * m_invPixelSize + m_invSlotSize + m_invDistanceBetweenSlots;
	setCraftingSlotsPositions({ craftStartPosX, craftStartPosY });

	int craftingTableStartPosX = m_craftingTableGUI.getGlobalBounds().left
		+ 30 * m_invPixelSize;
	int craftingTableStartPosY = m_craftingTableGUI.getGlobalBounds().top
		+ 17 * m_invPixelSize + m_invSlotSize;
	setCraftingTableSlotsPositions({ craftingTableStartPosX, craftingTableStartPosY });
}

void Inventory::setInventorySlotsPositions(const sf::Vector2i &inventoryStartPos)
{
	sf::Vector2i startSlotPos = {
		inventoryStartPos.x + (int)(8 * m_invPixelSize),
		inventoryStartPos.y - (int)(8 * m_invPixelSize) };

	// toolbar slots in inventory
	for (int j = 0; j < 9; ++j) {
		m_slots[j].position.x = startSlotPos.x + j * m_invDistanceBetweenSlots;
		m_slots[j].position.y = startSlotPos.y;

		//m_slots[j].slotId = static_cast<SlotId>(j);
	}

	startSlotPos.y -= 4 * m_invPixelSize + 3 * m_invDistanceBetweenSlots;

	// rest of the slots
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 9; ++j) {
			int slotIndex = (i + 1) * 9 + j;

			m_slots[slotIndex].position.x = startSlotPos.x + j * m_invDistanceBetweenSlots;
			m_slots[slotIndex].position.y = startSlotPos.y + i * m_invDistanceBetweenSlots;

			//m_slots[slotIndex].slotId = static_cast<SlotId>(slotIndex);
		}
	}
}

void Inventory::setToolbarSlotsPositions(const sf::Vector2i &toolbarStartPos)
{
	sf::Vector2i startSlotPos = {
		toolbarStartPos.x + (int)(m_toolbarDistanceBetweenSlots * 0.1f),
		toolbarStartPos.y - (int)(m_toolbarDistanceBetweenSlots * 0.081f) };

	for (int i = 0; i < 9; ++i) {
		m_toolbarItemPos[i] = sf::Vector2i(
			startSlotPos.x + i * m_toolbarDistanceBetweenSlots,
			startSlotPos.y);
	}
}

void Inventory::setArmorSlotsPositions(const sf::Vector2i& armorStartPos)
{
	for (int i = 0; i < 4; ++i) {
		m_armorSlots[i].position.x = armorStartPos.x;
		m_armorSlots[i].position.y = armorStartPos.y + i * m_invDistanceBetweenSlots;
		//m_armorSlots[i].slotId = static_cast<SlotId>(i);
	}
}

void Inventory::setCraftingSlotsPositions(const sf::Vector2i& craftingStartPos)
{
	for (int i = 0; i < 4; ++i) {
		int xOffset = (i % 2) * m_invDistanceBetweenSlots;
		int yOffset = (i / 2) * m_invDistanceBetweenSlots;

		m_craftSlots[i].position.x = craftingStartPos.x + xOffset;
		m_craftSlots[i].position.y = craftingStartPos.y + yOffset;
		//m_craftSlots[i].slotId = static_cast<SlotId>(i);
	}

	m_craftResultSlot.position.x = craftingStartPos.x + 2 * m_invDistanceBetweenSlots + 20.0f * m_invPixelSize;
	m_craftResultSlot.position.y = craftingStartPos.y + m_invDistanceBetweenSlots / 2.0f + m_invPixelSize;
	//m_craftResultSlot.slotId = SlotId::Craft_4;
}

void Inventory::setCraftingTableSlotsPositions(const sf::Vector2i& craftingTableStartPos)
{
	int index = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			m_craftingTableSlots[index].position.x = craftingTableStartPos.x + col * m_invDistanceBetweenSlots;
			m_craftingTableSlots[index].position.y = craftingTableStartPos.y + row * m_invDistanceBetweenSlots;
			index++;
		}
	}

	m_craftingTableResultSlot.position.x = craftingTableStartPos.x + 3 * m_invDistanceBetweenSlots + 40 * m_invPixelSize;
	m_craftingTableResultSlot.position.y = craftingTableStartPos.y + m_invDistanceBetweenSlots;
}

void Inventory::setTextSettings(const Application &app)
{
	m_inventoryItemText.setFont(m_font);
	m_inventoryItemText.setCharacterSize(40 * app.getWindow().getSize().x / 2560.0f);

	m_itemTextBackground.setSize(sf::Vector2f(0.0f, 60.0f * app.getWindow().getSize().x / 2560.0f));
	m_backgroundHeightOneString = m_itemTextBackground.getSize().y;

	m_toolbarItemText.setFont(m_font);
	m_toolbarItemText.setCharacterSize(40 * app.getWindow().getSize().x / 2560.0f);
	m_toolbarItemText.setPosition(
		app.getWindow().getSize().x / 2,
		app.getWindow().getSize().y * 0.865f);

	updateToolbarText();
}

void Inventory::setToolDurabilityBarSettings()
{
	m_toolDurBarOrigin = sf::Vector2f(-m_invSlotSize * 0.1f, m_invSlotSize * 0.23f);

	const sf::Vector2f ORIGIN{ m_invSlotSize * 0.41f, -m_invSlotSize * 0.5f };
	m_toolMaxDurBarGrabbedItem.setOrigin({ ORIGIN });
	m_toolDurBarGrabbedItem.setOrigin({ ORIGIN });
	m_toolMaxDurBarGrabbedItem.setFillColor(sf::Color::Black);
}
