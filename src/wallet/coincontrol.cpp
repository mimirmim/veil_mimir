// Copyright (c) 2019 The Bitcoin Core developers
// Copyright (c) 2019 The Veil developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <wallet/coincontrol.h>

#include <util.h>

void CCoinControl::SetNull()
{
    destChange = CNoDestination();
    m_change_type.reset();
    fAllowOtherInputs = false;
    fAllowWatchOnly = false;
    m_avoid_partial_spends = gArgs.GetBoolArg("-avoidpartialspends", DEFAULT_AVOIDPARTIALSPENDS);
    setSelected.clear();
    //m_feerate.reset();
    fOverrideFeeRate = false;
    m_confirm_target.reset();
    m_signal_bip125_rbf.reset();
    //m_fee_mode = FeeEstimateMode::UNSET;

    nCoinType = OUTPUT_STANDARD;
    fZerocoinSelected = false;
    fHaveAnonOutputs = false;
    m_extrafee = 0;

    setZerocoinSelected.clear();
    fProofOfStake = false;
}

